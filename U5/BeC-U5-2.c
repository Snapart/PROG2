// Berger Carola
// BEC_U5-2.c

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#define MAX_LINES     1000 // es sind maximal 1000 Zeilen vorgesehen
#define CHAR_PER_LINE  500

void free_arr(char** arr, unsigned arr_length)
{
	for(unsigned i = 0; i < arr_length; ++i)
	{
		free(arr[i]);
		arr[i] = NULL; // optional
	}
}



void bubble_sort(char** arr, unsigned arr_length, int is_aufsteigend)
{
	if (is_aufsteigend) // je nach User-Eingabe
	{
		is_aufsteigend = 1;
	}
	else
	{
		is_aufsteigend = -1;
	}


	for(unsigned i = 0; i < arr_length; ++i)    // pro element eine runde
	{
		for(unsigned j = 1; j < arr_length; ++j) // sortier-durchlauf
		{
			if(strcmp(arr[j-1], arr[j])*is_aufsteigend > 0)
			{
				char* tmp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void str_trim(char* str)
{
	size_t line_len = strlen(str);
	if (str[line_len-1] == '\n')
	{
		str[line_len-1] = '\0';
	}
}

int read_lines(FILE* source, char** lines, unsigned max_lines, int char_per_line)
{
	char line_buffer[char_per_line];
	char* _res;
	unsigned lines_read = 0;
	
	for(unsigned i = 0; i < max_lines; i++)
	{
		if(source == stdin)     // optional
		{                       // optional
			printf("%d> ", i+1);// optional
		}                       // optional
		_res = fgets(line_buffer, char_per_line, source);
		if (_res == NULL) {
			if (ferror(source) != 0)  // optional
			{                        // optional
				free_arr(lines, i);  // optional
				fprintf(stderr, "Stdin wurde aufgrund eines Fehlers beendet!\n");  // optional
				return -1;
			}
			else if(feof(source) != 0) // achtung: könnte error clearen
			{
				lines_read = i;
				for(; i < max_lines; i++) // optional
				{                         // optional
					lines[i] = NULL;      // optional
				}                         // optional
				break;
			}
			else
			{
				free_arr(lines, i);
				fprintf(stderr, "Stdin wurde unerwartet beendet!\n");
				return -2;
			}
		}

		str_trim(line_buffer);

		_res = strdup(line_buffer);
		if (_res == NULL)   // optional
		{                   // optional
			fprintf(stderr, "Unzureichend RAM vorhanden!\n");  // optional
			return -3;       // optional
		}                   // optional
		lines[i] = _res;
	}
	return (int) lines_read;
}

int main(int argc, char** argv)
{
	char* lines[MAX_LINES];
	unsigned lines_read = 0;
	int _lines_read = 0;
	
	// printf("DEBUG Args:\n");      // optional
	for(int i = 0; i < argc; ++i) // optional
	{                             // optional
		// printf("DEBUG \t%d: %s\n", i, argv[i]); // optional
	}                            // optional

	int is_aufsteigend = 1;

	if(argc > 1) // mit args aufgerufen
	{
		FILE* fp;
		for(int i = 1; i < argc; ++i)
		{
			if(i == 1 && strcmp(argv[1],"-d") == 0) // sortierreihenfolge
			{
				is_aufsteigend = 0;
			}
			else // files
			{
				fp = fopen(argv[i], "r");
				if (fp == NULL)
				{
					fprintf(stderr, "Konnte File '%s' nicht öffnen!\n", argv[i]);
					continue;
				}

				_lines_read = read_lines(
					fp,
					lines+lines_read,     // array (weiter) auffüllen
					MAX_LINES-lines_read, // max length abhaenging von bisherigen inputs
					CHAR_PER_LINE);
				printf("DEBUG es konnten %d Zeilen aus '%s' gelesen werden\n", 
					_lines_read,
					argv[i]);
				if(fclose(fp) != 0)
				{
					fprintf(stderr, "konnte '%s' nicht korrekt schliessen\n", argv[i]);
				}
				if(_lines_read < 0)
				{
					continue;
				}
				lines_read += (unsigned) _lines_read;
			}
		}
	}
	printf("es wird %s sortiert\n", is_aufsteigend == 0 ? "absteigend" : "aufsteigend");

	if(lines_read == 0) // lies nur stdin wenn nicht bereits files angegbeen
	{
		_lines_read = read_lines(stdin, lines, MAX_LINES, CHAR_PER_LINE);
		if(_lines_read < 0)
		{
			return -_lines_read;
		}

		lines_read = (unsigned) _lines_read; // optional
	}

	bubble_sort(lines, lines_read, is_aufsteigend);
	printf("\n\nSortierte Eingaben:\n");
	for(unsigned i = 0; i < lines_read; ++i)
	{
		printf("%s\n", lines[i]);
	}

	free_arr(lines, lines_read);
	return 0;
}

