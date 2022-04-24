// Carola Berger
// BeC-U1-3.c


#include <stdio.h>
#include <math.h>

int corx;
int cory;
int zcorx;
int zcory;
int a;
double a2;
double b2;
int b;
double distance;


int main()
{
        // Eingabe der Koordinaten
        printf ("Start-X: ");
        scanf("%d", &corx);
        printf ("Start-Y: ");
        scanf("%d", &cory);

        printf ("Ziel-X: ");
        scanf("%d", &zcorx);
        printf ("Ziel-Y: ");
        scanf("%d", &zcory);
        // printf ("Deine Zielkoordinaten lauten: x=%d y=%d\n\n",zcorx,zcory);
        
        // Berechnung der Katheten
        if (corx>zcorx)
        {
                a = corx-zcorx;
        }
        else
        {        
                a = zcorx-corx;
        }
        // printf ("a beträgt %d\n",a);

       if (cory>zcory)
        {
                b = cory-zcory;
        }
        else
        {        
                b = zcory-cory;
        }
        // printf ("b beträgt %d\n",b);


        a2 = pow(a,2); //a hoch 2
        b2 = pow(b,2); //b hoch 2
        distance = sqrt(a2+b2); // Berechnung Hypothenuse
        printf ("\nDistanz: %.4lf\n", distance); // Ausgabe mit 4 Nachkommastellen

        // Rictungen
        // 1. Weg zwischen den Koordinaten auf x oder y-Achse länger
        // 2. Start- oder Zielkoordinate größer.
        if (a<b && cory<zcory)
        {
                printf ("Hauptbewegungsrichtung: nach oben\n");
        }
        if (a<b && cory>zcory)
        {
                printf ("Hauptbewegungsrichtung: nach unten\n");
        }
        if (a>b && corx<zcorx)
        {
                printf ("Hauptbewegungsrichtung: nach rechts\n");
        }
        if (a>b && corx>zcorx)
        {
                printf ("Hauptbewegungsrichtung: nach links\n");
        }
        if (a == b && corx != zcorx && cory != zcory) // Weg in 2 Richtungen gleich       
        {
                printf ("Keine eindeutige Richtung\n");
        }
        if (a == b && corx == zcorx && cory == zcory) // selben Koordinaten
        {
                printf ("Keine Bewegung - I'd like to move it, move it!\n");
         }
}
