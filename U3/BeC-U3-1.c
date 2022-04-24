// Carola Berger
// BeC-U3-1.c
// #einHerzfuerRoemer

#include <stdio.h>

int main()
{
        printf("Enter num: ");
        int input = -1;
        scanf("%d", &input);

        // Standard + Sonderfälle
        int count = 13; //0  1     2    3   4    5    6    7    8    9   10   11    12
        int values[] = {  1, 4,    5,   9, 10,  40,  50,  90, 100, 400, 500, 900, 1000};
        char* symb[] = {"I","IV","V","IX", "X","XL","L","XC", "C","CD", "D","CM",  "M"};

        while(input > 0) // solange noch nicht alles abgearbeitet
        {
                for(int idx = count-1; idx >= 0; --idx){ // vom groessten zum kleinsten Wert
                        while(values[idx] <= input) // so oft wie enthalten
                        {
                                printf("%s", symb[idx]); // ausgeben
                                input -= values[idx];    // abziehen
                        }       
                } 
        }
        printf("\n");
}
