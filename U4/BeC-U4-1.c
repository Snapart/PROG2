// Carola Berger
// BeC-U4-1.c



#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>




void BelowerC(char *input)
{
        for(char *work=input; *work != '\0'; work++)
        {
                *work =  (char) tolower(*work);   
        }
}


void BeshiftDigitsC(char *input)
{
        for(char *num=input; *num != '\0'; num++)
        {

                if(isdigit(*num) && *num != '0')
                {
                        //int digit = atoi(num)-1;
                        int digit = *num-'1';
                        // printf("DEBUG input='%s' current char=%c=%d digit=%d\n", num, *num, *num, digit);
                        *num = digit+'0';
                        // printf("isdigit erreicht!\n%i\n", digit);
                        // printf("DEBUG after mod input='%s' current char=%c=%d\n", num, *num, *num);
                }
                else if(isdigit(*num) && *num == '0')
                        *num = '9';
        }
}


void BeshortenC(char *input)
{

        for(long i = (long) strlen(input)-1; i>=0; --i)
        {
                if(isalpha(input[i]) || isdigit(input[i]))
                {
                        break;
                }
                else
                {
                        input[i] = '\0';
                }
        }
}



int main()
{
        char input[1024];
        for(;;)
        {
                printf("Eingabe: ");

                size_t len;
                if(fgets(input, 1024, stdin) == NULL)
                {
                        break;
                }
                len = strlen(input);
                if(input[len-1] == '\n')
                {
                        len -= 1;
                        input[len] = '\0';
                }
                if(strcmp(input, "quit") == 0)
                {
                        break;
                }
                
                
                
                BelowerC(input);
                printf("Ausgabe Belower:     %s\n", input);
                BeshiftDigitsC(input);
                printf("Ausgabe Beshift:     %s\n", input);

                BeshortenC(input);
                printf("Ausgabe Beshorten:   %s\n", input);
        }
}
