// Carola Berger
// BeC-U5-1.c

#include <stdio.h>
#include <string.h>

unsigned BeC_einlesen(int* arr, unsigned arr_len) // unsigned, weil das Array nie -1 sein kann
{
        for(int* max = arr+arr_len, *ptr=arr; ptr < max; ++ptr)
        {
                if (scanf(" %d", ptr) == 0) // früher: ***if (scanf(" %d", &arr[i]) == 0)***; wenn er keine Ziffern mehr einlesen kann
                {
                        return ptr-arr; // in dem Fall weniger als maximale Anzahl Elemente
                }
        }
        return arr_len; // Länge des Arrays - also maximale
}

int BeC_mittelwertErmitteln(int* arr, unsigned arr_len)
{
        long sum = 0; // long, da die Summe von int größer als ein int sein kann
        for(unsigned i = 0; i < arr_len; ++i)
        {
                sum += *(arr+i); // früher: ***sum+= arr[i];***; addiert alle Werte
        }
        sum /= arr_len; // berechnet Mittelwert
        return (int) sum; // gibt wieder einen int zurück
}

unsigned idx_min_val(int* arr, unsigned arr_len) // gibt Index von Arrayelement mit kleinstem Wert zurück
{
        unsigned min_idx = 0; // theoretische Annahme -> Element 0 hat kleinsten Wert
        for(unsigned i = 1; i < arr_len; ++i)
        {
                if(arr[i] < *(arr+min_idx)) // früher: ***if(arr[i] < arr[min_idx])***; wenn das aktuelle Element kleiner ist als das derzeit bekannteste kleinste Element
                {
                        min_idx = i; // ersetze es
                }
        }
        return min_idx; // gibt Index zurück, wo das kleinste Element steht
}

int BeC_getMin(int* arr, unsigned arr_len)
{
        return *(arr+idx_min_val(arr, arr_len)); // früher ***return arr[idx_min_val(arr, arr_len)];***; gibt nun nicht den Index, sondern den Wert zurück
}

void swap_values(int* arr, unsigned idx_a, unsigned idx_b) // 3-Wege-Tausch
{
        int tmp = *(arr+idx_a); // früher ***int tmp = arr[idx_a];***
        *(arr+idx_a) = *(arr+idx_b); // früher ***arr[idx_a] = arr[idx_b];***
        *(arr+idx_b) = tmp; // früher ***arr[idx_b] = tmp;***
}

void BeC_sortieren(int* arr, unsigned arr_len) // Selection Sort - sucht kleinstes Element und schreibt es an nächste zu besetzende Stelle 
{
        for(unsigned i = 0; i < arr_len; ++i)
        {
                unsigned idx = idx_min_val(arr+i, arr_len-i)+i; // nimm das kleinste Elemente, setzen es an die erste Stelle, verkürze die zu überprüfende Liste
                //printf("%u: min idx=%u\n", i, idx);
                swap_values(arr, i, idx);
        } 
}

unsigned get_diff(int a, int b) // Abstand berechnen - Vorbereitung für andere Funktion
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

unsigned get_diff_pair(int* arr, unsigned lower_idx) // Paar ausgeben - Vorbereitung für andere Funktion
{
        return get_diff(*(arr+lower_idx), *(arr+lower_idx+1)); // früher ***return get_diff(arr[lower_idx], arr[lower_idx+1]);***
}

int BeC_benachbarteMitMinimalemAbstandErmitteln(int* arr, unsigned arr_len)
{
        if(arr_len < 2)
        {
                return -1; // Fehler
        }
        unsigned min_idx = 0; // wieder theoretische Annahme, dass 0 und Nachbar den geringsten Abstand haben
        unsigned min_dist = get_diff_pair(arr, 0);
        for(unsigned i = 1; i + 1 < arr_len; ++i)
        {
                unsigned dist = get_diff_pair(arr, i);
                if (dist < min_dist) // wenn aktueller Abstand geringer als bisher bekannter kleinster Abstand
                {
                        min_dist = dist; // -> ersetzen
                        min_idx = i; // i ist kleinerer Index der beiden Parameter
                }
        }
        return (int) min_idx; // gibt kleineren Index zurück - nun wieder als int (mit -1 war Fehler möglich)
}

int BeC_getMax(int* arr, unsigned arr_len) // wie BeC_getMin -> aber umgekehrt
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
        unsigned anzahl_max = 10; // ANPASSEN: Maximaler Input
        int arr[anzahl_max]; // Array in der gewählten Größe
        printf("Bis zu %u Zahlen können eingegeben werden\n", anzahl_max);
        unsigned anzahl = BeC_einlesen(arr, anzahl_max); // wie viel wurde wirklich eingegeben?
        printf("es wurden %u Zahlen eingegeben\n", anzahl);
        printf("Mittelwert: %i\n", BeC_mittelwertErmitteln(arr, anzahl));
        printf("Sorted: ");
        BeC_sortieren(arr, anzahl);
        for(unsigned i = 0; i < anzahl; ++i)
        {
                printf("%d", arr[i]); // geben sortiertes Array aus
                if(i != anzahl -1)
                {
                        printf(", "); // Wenn es nicht das letzte Element ist, mach einen Beistrich
                }
        }
        printf("\n");
        int paar_idx = BeC_benachbarteMitMinimalemAbstandErmitteln(arr, anzahl);
        if (paar_idx < 0)
        {
                printf("Weniger als 2 Elemente enthalten!\n");
        }
        else
        {
                printf("Paar mit minimalen Abstand: %i: %d & %i: %d\n", 
                                paar_idx, *(arr+paar_idx), // früher: ***paar_idx, arr[paar_idx],***
                                paar_idx+1, *(arr+paar_idx+1)); // früher ***paar_idx+1, arr[paar_idx+1]);***
        } // %i für Indices und %d für Werte
        printf("Min: %d, Max: %d\n", BeC_getMin(arr, anzahl), BeC_getMax(arr, anzahl));
}
