// Carola Berger
// BeC-U2-4.c


#include <stdio.h>

int height, growth;


int main ()
{
        /*** Eingabe Parameter ***/
        printf("Höhe: ");
        scanf("%d", &height);
        printf("Breitenwachstum: ");
        scanf("%d", &growth);

        /*** Baum ***/
        int max_w = 1 + (height-1)*growth; // erste Zeile berücksichtigen
                                           // Hilfsausgabe -> printf("max_w=%d\n", max_w);        
        int w = 1;
        for(int i=0; i < height; ++i)
        {
                if(i != 0)
                {
                        w += growth;       
                }
                int spaces = (max_w - w)/2;
                for(int j=0; j<spaces; ++j)
                {
                        printf(" ");
                }
                for(int j=0; j<w; ++j)
                {
                        printf("C");       
                }
                printf("\n"); // beende Reihe des Baumes
        }

        /*** Leerzeichen ***/
        for(int j=0;j<max_w/2;++j) // Verwenung halbierte maximale Breite
        {
                printf(" ");
        }

        /*** Stamm ***/
        printf("B\n");
}


