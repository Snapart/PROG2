// Carola Berger
// BeC-U4-3.c

#include <stdio.h>
#include <string.h>

unsigned BEC_einlesen(int* arr, unsigned arr_len)
{
	for(unsigned i=0; i < arr_len; ++i)
	{
		if (scanf(" %d", &arr[i]) == 0)
		{
			return i;
		}
	}
	return arr_len;
}

int BEC_mittelwertErmitteln(int* arr, unsigned arr_len)
{
	long sum = 0;
	for(unsigned i = 0; i < arr_len; ++i)
	{
		sum += arr[i];
	}
	sum /= arr_len;
	return (int) sum;
}

unsigned idx_min_val(int* arr, unsigned arr_len)
{
	unsigned min_idx = 0;
	for(unsigned i = 1; i < arr_len; ++i)
	{
		if(arr[i]  < arr[min_idx])
		{
			min_idx = i;
		}
	}
	return min_idx;
}

int BEC_getMin(int* arr, unsigned arr_len)
{
	return arr[idx_min_val(arr, arr_len)];
}

void swap_values(int* arr, unsigned idx_a, unsigned idx_b)
{
	int tmp = arr[idx_a];
	arr[idx_a] = arr[idx_b];
	arr[idx_b] = tmp; 
}

void BEC_sortieren(int* arr, unsigned arr_len)
{
	for(unsigned i = 0; i < arr_len; ++i)
	{
		unsigned idx = idx_min_val(&arr[i], arr_len-i)+i;
		printf("%u: min idx=%u\n", i, idx);
		swap_values(arr, i, idx);
	}	
}

unsigned get_diff(int a, int b)
{
	if(a > b)
	{
		return (unsigned)(a - b);
	}
	else
	{
		return (unsigned)(b - a);
	}
}

unsigned get_diff_pair(int* arr, unsigned lower_idx)
{
	return get_diff(arr[lower_idx], arr[lower_idx+1]);
}

int BEC_benachbarteMitMinimalemAbstandErmitteln(int* arr, unsigned arr_len)
{
	if(arr_len < 2)
	{
		return -1;
	}
	unsigned min_idx = 0;
	unsigned min_dist = get_diff_pair(arr, 0);
	for(unsigned i = 1; i + 1 < arr_len; ++i)
	{
		unsigned dist = get_diff_pair(arr, i);
		if (dist < min_dist)
		{
			min_dist = dist;
			min_idx = i;
		}
	}
	return (int) min_idx;
}

int BEC_getMax(int* arr, unsigned arr_len)
{
	int max_val = arr[0];
	for(unsigned i = 1; i < arr_len; ++i)
	{
		if(arr[i] > max_val)
		{
			max_val = arr[i];
		}
	}
	return max_val;
}

int main(){
	unsigned anzahl_max = 10;
	int arr[anzahl_max];
	printf("Bis zu %u Zahlen können eingegeben werden\n", anzahl_max);
	unsigned anzahl = BEC_einlesen(arr, anzahl_max);
	printf("es wurden %u Zahlen eingegeben\n", anzahl);
	printf("Mittelwert: %i\n", BEC_mittelwertErmitteln(arr, anzahl));
	printf("Sorted: ");
	BEC_sortieren(arr, anzahl);
	for(unsigned i = 0; i < anzahl; ++i)
	{
		printf("%d", arr[i]);
		if(i != anzahl -1)
		{
			printf(", ");
		}
	}
	printf("\n");
	int paar_idx = BEC_benachbarteMitMinimalemAbstandErmitteln(arr, anzahl);
	if (paar_idx < 0)
	{
		printf("Weniger als 2 Elemente enthalten!\n");
	}
	else
	{
		printf("Paar mit minimalen Abstand: %i: %d & %i: %d\n", 
			paar_idx, arr[paar_idx],
			paar_idx+1, arr[paar_idx+1]);
	}
	printf("Min: %d, Max: %d\n", BEC_getMin(arr, anzahl), BEC_getMax(arr, anzahl));
}
