
#include <stdio.h>
#include "BeC_RiverFkt.h"



int BeC_digitsum (int num)
{      
        int sum = 0, mod;

        //printf("Eingabe\n");
        //scanf("%d", &num);


        while (num != 0)
        {
                mod = num % 10; // beginnt sich von der hintersten Ziffer vor zuarbeiten
                sum += mod; // rechnet neuestes Modulo zum bestehenden dazu
                num /= 10;  // übergibt die Zahl minus der letzten Ziffer an die Schleife zurück und beendet die While-Schleife, wenn die gesamte Zahl verarbeitet wurde
        }

        //printf("Summe = %d\n", sum);

        return sum;
}

int BeC_NextRiverNum (int num)
{

            num += BeC_digitsum(num);
            //printf("...%d\n", num);
            return num;
                        
}
