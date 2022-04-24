// Carola Berger
// BeC-U1-4.c


#include <stdio.h>

// zur Übersichtlichkeit in Variablen
int sec;
int day = 86400;
int hour = 3600;
int min = 60;

// Ablauf wie bei Aufgabe 1
int main ()
{
        printf ("Bitte gib eine Zeitspanne in Sekunden ein: ");
        scanf ("%d", &sec);

        if (sec/day !=0)
        {
                printf ("%5d Tage\n", sec/day);
                sec -= day*(sec/day);
        }
        // printf ("%d Rest\n", sec);
        if (sec/hour !=0)
        {
                printf ("%5d Stunden\n", sec/hour);
                sec -= hour*(sec/hour);
        }
        // printf ("%d Rest\n",sec);
        if (sec/min != 0)
        {        
                printf ("%5d Minuten\n", sec/min);
                sec -= min*(sec/min);
        }
        printf ("%5d Sekunden \n", sec);
}


