// Carola Berger
// datum.c

#include "date_help.h" // Verbindung zum Modul
#include <stdio.h>


int main ()
{       // Variablen werden zur Fehlerbehandlung mit entsprechenden Werten versehen
        int day = -1;
        int month = -1;
        int year = 0; // ein Herz für Römer

        /*** Tag ***/
        printf("Gib einen Tag ein: ");
        scanf("%d", &day);
        
        // ungültiger Ausdruck für Tag
        if(day == -1) // wenn scanf nie etwas Schreiben konnte, steht immer noch "-1" in der Variable
        {
                printf("oarsch\n");
                return -1;
        }

        /*** Monat ***/
        printf("Gib einen Monat ein: ");
        scanf("%d", &month);
        if(month == -1) // wenn scanf nie etwas Schreiben konnte, steht immer noch "-1" in der Variable
        {
                printf("oarsch\n");
                return -1;
        }

        /*** Jahr ***/
        printf("Gib ein Jahr ein: ");
        scanf("%d", &year);        


        /*** Checks ***/
        if (month < 1 || month > 12) // Überprüfen ob Monat möglich
        {
                printf ("%d entspricht keinem Monat\n", month);
                return 1;
        }

        if (day < 1 || day > 31) // Überprüfen ob Tag generell möglich
        {
                printf ("%d entspricht keinem Tag\n", day);
                return 2;
        }
        
        printf("\nDei Datum %d.%d.%d ", day, month, year);
        
        /*** Schaltjahr (Schlatjahr)***/
        int leap = is_leap(year); // Aufruf Funktion zum Schaltjahr

        if(leap)
        {
                printf("is a Schlatjahr\n");
        }
        else
        {
                printf("is ka Schlatjahr\n");

        }

        /*** Anzahl Tage ***/
        int max_days = days_in_month(year, month); // Aufruf Funktion zur Tagesanzahl des Monats
        
        if (day > max_days)
        {
                printf("User du bist'n Trottl Monat %d hot' %d Tog'!\n",month, max_days); // Zahl größer als Tage -> User ist ein Trottel
                return 3;        
        }
        printf ("Bravo, du konnst a Datum schreibn'\n");

        /*** Summe der Tage im gewaehlten Jahr ***/
        int sum = day;
        for(int m = 1; m < month; m++)
        {
               sum += days_in_month(year, m); // Zaehlen der Tage
        }
        printf ("Du host' scho' %d Tog' vom Jahr %d überlebt - guat' g'macht\n", sum, year); // YAY

}

