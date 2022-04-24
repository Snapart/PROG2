// Carola Berger
// BeC-U3-3.c

#include <stdio.h>
#include "BeC_RiverFkt.h"


int main ()
{
        int num;

        printf("Eingabe: ");
        scanf("%d", &num);

        int sum = BeC_digitsum(num);
        printf("Summe = %d\n", sum);


        for (int i=0; i<20; i++)
        {
                printf("%d\n", num);
                num = BeC_NextRiverNum(num);
        }
}

