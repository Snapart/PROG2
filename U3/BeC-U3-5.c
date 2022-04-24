
#include <stdio.h>
#include <stdint.h>

int main()
{

        /*** Der traurige Versuch einer schönen Lösung :( ***/
        /*
           char *type[21] = {
           "char",
           "int8_t",
           "unsigned char",
           "uint8_t",
           "short",
           "int16_t",
           "uint16_t",
           "int",
           "unsigned",
           "long",
           "unsigned long",
           "int32_t",
           "uint32_t",
           "long long",
           "int64_t",
           "unsigned long long",
           "uint64_t",
           "float",
           "double",
           "long double",
           "_Bool",
           };

           for (int i =0; i< 21; i++)
           {

           printf("%d, %s, %zu\n", i, type[i], sizeof((type[i])));
           }
         */

                printf("Type                  Bytes\n\n------------------------------------\n\n"); // Spaltenbeschriftung

                printf("char                    %zu\n", sizeof(char));
                printf("int8_t                  %zu\n", sizeof(int8_t));
                printf("unsigned char           %zu\n", sizeof(unsigned char));
                printf("uint8_t                 %zu\n", sizeof(uint8_t));
                printf("short                   %zu\n", sizeof(short));
                printf("int16_t                 %zu\n", sizeof(int16_t));
                printf("uint16_t                %zu\n", sizeof(uint16_t));
                printf("int                     %zu\n", sizeof(int));
                printf("unsigned                %zu\n", sizeof(unsigned));
                printf("long                    %zu\n", sizeof(long));
                printf("unsigned long           %zu\n", sizeof(unsigned long));
                printf("int32_t                 %zu\n", sizeof(int32_t));
                printf("uint32_t                %zu\n", sizeof(uint32_t));
                printf("long long               %zu\n", sizeof(long long));
                printf("int64_t                 %zu\n", sizeof(int64_t));
                printf("unsigned long long      %zu\n", sizeof(unsigned long long));
                printf("uint64_t                %zu\n", sizeof(uint64_t));
                printf("float                   %zu\n", sizeof(float));
                printf("double                  %zu\n", sizeof(double));
                printf("long double             %zu\n", sizeof(long double));
                printf("_Bool                   %zu\n", sizeof(_Bool));



}
