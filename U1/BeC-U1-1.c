// Carola Berger
// BeC-U1-1.c

#include <stdio.h>
#include <math.h>


int betrag; // wird später durch den User eingegeben
// die folgenden Variablen dienen der korrekten Grammatik
char schein[] = "Schein ";
char scheine[] = "Scheine";
char muenze[] = "Münze  ";
char muenzen[] = "Münzen ";


int main ()
{
        printf ("Input (Der Betrag wird auf ganze Euros gerundet): "); // Aufforderung zur Eingabe
        scanf("%d", &betrag); // Eingabe durch User

        printf ("%d Euro entspricht ca. %ld Schilling\n",betrag, lround(betrag*13.7603)); // Ausgabe des eingegebenen Betrags als int und der gerundeten Berechnung als long int

        printf ("In Geldscheinen und Münzen:\n\n");
        
        // Aufteilung der Beträge
        if (betrag/200 != 0) // wenn der Betrag größer als 200 ist, kann die mögliche Anzahl der Scheine berechnet werden
        {
                printf ("%5d %s mit Wert %d\n",betrag/200,betrag/200>1 ? scheine:schein,200); // Umsetzung der Grammatik und Formatierung; Berechnung der Stückzahl 
                betrag -= (betrag/200)*200; // Abzug der erreichten Stückelung
                //printf("Erstes if = %d\n\n",betrag);
        }
        //printf("Print Main = %d\n\n",betrag);
        if (betrag/100 != 0)
        {
                //printf ("Anfang 2. if = %d\n", betrag);
                printf ("%5d %s mit Wert %d\n",betrag/100,betrag/100>1 ? scheine:schein,100);
                betrag -= (betrag/100)*100;
                //printf("Zweites if = %d\n\n",betrag);
        }
        if (betrag/50 != 0)
        {
                printf ("%5d %s mit Wert %d\n",betrag/50,betrag/50>1 ? scheine:schein,50); 
                betrag -= (betrag/50)*50;        
        }
        if (betrag/20 != 0)
        {
                printf ("%5d %s mit Wert %d\n",betrag/20,betrag/20>1 ? scheine:schein,20); 
                betrag -= (betrag/20)*20;
        }
        if (betrag/10 != 0)
        {
                printf ("%5d %s mit Wert %d\n",betrag/10,betrag/10>1 ? scheine:schein,10); 
                betrag -= (betrag/10)*10;
        }
        if (betrag/5 != 0)
        {
                printf ("%5d %s mit Wert %d\n",betrag/5,betrag/5>1 ? scheine:schein,5); 
                betrag -= (betrag/5)*5;
        }
        if (betrag/2 != 0)
        {
                printf ("%5d %s mit Wert %d\n",betrag/2,betrag/2>1 ? muenzen:muenze,2); 
                betrag -= (betrag/2)*2;                                                                                                                    
        }
        if (betrag/1 != 0)
        {
                printf ("%5d %s mit Wert %d\n",betrag/1,betrag/1>1 ? muenzen:muenze,1); 
                betrag -= (betrag/1)*1;                                                           
        }        






}

