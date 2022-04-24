// Carola Berger
// datum.c

#include "date_help.h"




int is_leap(int year)
{
        /*** Berechnung Schaltjahr ***/
        if(
                (year%4) ? 
                0 :                     // nicht durch 4 teilbar
                (                       // durch 4 teilbar
                        (year%100) ? 
                        1 :             // nicht durch 100 teilbar -> ist Schalt
                        year%400 == 0   // durch 100 teilbar -> wenn durch 400 teilbar -> Schalt
                )
        )
        {
                return 1; // Schaltjahr
        }
        else
        {
                return 0; // keine Schaltjahr
        }
        
}


int days_in_month(int year, int month) 
{
        /*** Tage im Monat festlegen ***/
        int leap = is_leap (year); // 1 = Schaltjahr, 0 = kein Schaltjahr

        switch (month)
        {
                case 1: return 31; 
                case 2: return (leap ? 29 : 28); // Wenn Schaltjahr 29, sonst 28
                case 3: return 31; 
                case 4: return 30; 
                case 5: return 31; 
                case 6: return 30; 
                case 7: return 31; 
                case 8: return 31; 
                case 9: return 30; 
                case 10: return 31; 
                case 11: return 30; 
                case 12: return 31; 
                default: return -1; 
        }
        // cannot be reached
}

char* name_of_month (int month)
{ 
        /*** Namen der Monate ***/
        switch (month)
        {
                case 1: return "Januar"; 
                case 2: return "Februar"; 
                case 3: return "Maerz"; 
                case 4: return "April"; 
                case 5: return "Mai"; 
                case 6: return "Juni"; 
                case 7: return "Juli"; 
                case 8: return "August"; 
                case 9: return "September"; 
                case 10: return "Oktober"; 
                case 11: return "November"; 
                case 12: return "Dezember"; 
                default: return "UNBEKANNT LOL"; 

        }
}
