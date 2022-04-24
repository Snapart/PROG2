// Carola Berger
// BeC-U2-2.c


#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

double  a, b, c, a2, b2, c2, u, A; // Dreieck-Parameter 
int done; // Variable für allgemeines Dreieck

int main ()
{
        for (;;) // endless-Loop
        {
                /*** Eingabe Variablen ***/
                printf("Seite a: ");
                scanf("%lf", &a);
                printf("Seite b: ");
                scanf("%lf", &b);
                printf("Seite c: ");
                scanf("%lf", &c);

                u = a+b+c; // Berechnung Umfang
                A = (sqrt((a+b+c)*(a+b-c)*(b+c-a)*(c+a-b)))/4; // Berechnung der Flaeche fuer alle Dreiecke gueltig

                if (a+b <=c || a+c <= b || b+c <= a) // würde kein Dreieck ergeben
                {
                        printf ("Kein Dreieck - bitte Parameter erneut eingeben\n\n\n");
                        continue; // Eingabe erneut möglich
                }
                
                printf ("Fläche: %0.2lf, Umfang: %0.2lf\n", A, u); // Ausgabe Berechnungen

                /*** Gleichseitiges Dreieck ***/
                if (a == b && b == c)
                {
                        printf("Oh, es ist gleichseitig\n");
                        done = 1;
                }

                a2 = pow(a,2); //a hoch 2
                b2 = pow(b,2); //b hoch 2
                c2 = pow(c,2); //c hoch 2

                /*** Rechtwinkliges Dreieck ***/ 
                if ((c2 == a2+b2)|(a2 == b2+c2)|(b2 == a2+c2))
                {
                        printf ("Uiiii toll, ein rechter Winkel\n");
                        done =1;
                }


                /*** Gleichschnekliges Dreieck ***/ 
                if((a == b) | (a == c) | (b == c))
                {
                        printf ("Aha, gleichschneklig\n");
                        done = 1;
                }
                /*** Allgemeines Dreieck ***/ 
                if (done != 1)
                {
                        printf ("Allgemeines Dreieck...laaaaaaaaaaaaaaaangweilig\n");
                }
                break;
        }
}





