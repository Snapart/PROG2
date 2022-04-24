// Carola Berger
// BeC-U1-2.c

// #include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int tmp;
char einheit; 


int main()
{
        printf ("Bitte gib einen Temperaturwert ein:\n");
        // scanf ("%d", &tmp);

        if (scanf("%d", &tmp)!=1) // Abfangen falscher Eingaben
        {
                printf ("Bitte starte das Programm erneut und gib eine ganze Zahl als Temperaturwert ein!\n");
        }        
        else
        {       
        printf ("Bitte wähle eine Einheit (Fahrenheit=F, Celsius=C, Kelvin=K, Rakine=R)\n");
        }
        scanf (" %c", &einheit); // Auswahl Einheit

        switch (toupper(einheit)) // nimmt den Userinput unabhängig der Groß-/Kleinschreibung
        {
        // je nach gewählter Einheit springt das Programm        
        case ('F'): 
                printf ("%d %c entsprechen %ld °C\n",tmp, einheit,lround((tmp-32)/1.8)); // umrechnen in Celsius
                printf ("%d %c entsprechen %ld K\n",tmp, einheit,lround((tmp+459.67)*5/9)); // umrechnen in Kelvin
                printf ("%d %c entsprechen %ld °Ra\n",tmp, einheit,lround(tmp+459.67)); // umrechnen in Rankine
                break;
        case ('C'):
                printf ("%d %c entsprechen %ld °F\n",tmp, einheit,lround((tmp*1.8)+32)); // umrechnen in Fahrenheit
                printf ("%d %c entsprechen %ld K\n",tmp, einheit,lround(tmp+273.15)); // umrechnen in Kelvin
                printf ("%d %c entsprechen %ld °Ra\n",tmp, einheit,lround((tmp+273.15)*9/5)); // umrechnen in Rankine
                break;
        case ('K'):
                printf ("%d %c entsprechen %ld °F\n",tmp, einheit,lround((tmp*1.8)-459.67)); // umrechnen in Fahrenheit  
                printf ("%d %c entsprechen %ld °C\n",tmp, einheit,lround(tmp-273.15)); // umrechnen in Celsius
                printf ("%d %c entsprechen %ld °Ra\n",tmp, einheit,lround(tmp*9/5)); // umrechnen in Rankine
                break;
        case ('R'):
                printf ("%d %c entsprechen %ld °F\n",tmp, einheit,lround((tmp-459.67))); // umrechnen in Fahrenheit
                printf ("%d %c entsprechen %ld °C\n",tmp, einheit,lround((tmp-459.67)*5/9)); // umrechnen in Celsius
                printf ("%d %c entsprechen %ld K\n",tmp, einheit,lround(tmp*5/9)); // umrechnen in Kelvin
                break;      
        default:
                break;
        }


}
