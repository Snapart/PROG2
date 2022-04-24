// Carola Berger
// BeC-U3-4.c

#include <stdio.h>
#include "BeC_RiverFkt.h"

int meets_river(int start, int goal)
{
        while(start < goal)
        {
                start = BeC_NextRiverNum(start);
        }
        if (start == goal)
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

int main ()
{
        int num;

        printf("Eingabe: ");
        scanf("%d", &num);

        for(int smaller = 1; smaller < num; ++smaller)
        {
                if (meets_river(smaller, num) == 1)
                {
                        printf("%d meets %d\n", smaller, num);
                }
        }
}

