// Carola Berger
// BeC-U2-3.c

#include "date_help.h"
#include <stdio.h>


int main ()
{
        for (;;)
        {

                int month = -1;

                /*** Eingabebedingungen***/

                printf("Gib einen Monat ein: ");
                scanf("%d", &month);
                if(month == -1) // wenn scanf nie etwas Schreiben konnte, steht immer noch "-1" in der Variable
                {
                        printf("Falsche Eingabe\n");
                        return -1;
                }
                if(month == 0) // beende das Programm bei Eingabe "0"
                {
                        return 1;
                }
                if(month > 12) // Fehlermeldung und erneute Eingabe
                {
                        printf("ACHTUNG! Das Jahr hat nur 12 Monate - bitte Eingabe erneut versuchen\n");
                        continue;
                }

                /*** Name des Monats ***/

                char* month_name = name_of_month(month); 
                printf ("%s hat ", month_name);

                /*** Laenge des Monats ***/

                int max_days = days_in_month(2022, month);
                printf ("%d Tage\n", max_days);
        }
}

