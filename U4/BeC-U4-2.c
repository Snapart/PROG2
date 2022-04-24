// Carola Berger
// BeC-U4-2.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>


const char * BeCstrcichr (const char *s, char c);
const char * BeCstrrcichr (const char *s, char c);
const char * BeCstrcipbrk (const char *s, const char *accept);


const char * BeCstrcichr (const char *s, char c)
{
	int c_low = tolower(c);
	for(char* work = (char*) s; *work != '\0'; ++work)
	{
		if(tolower(*work) == c_low)
		{
			return (const char*) work;
		}
	}
	return NULL;
}

const char * BeCstrrcichr (const char *s, char c)
{
	int c_low = tolower(c);
	for(ssize_t i = ((ssize_t)strlen(s))-1; i > 0; --i)
	{
		if(tolower(s[i]) == c_low)
		{
			return (const char*) &s[i];
		}
	}
	return NULL;
}

const char * BeCstrcipbrk (const char *s, const char *accept)
{
	size_t accept_len = strlen(accept);
	int accept_lower[accept_len];
	for(size_t i = 0; i < accept_len; ++i)
	{
		accept_lower[i] = tolower(tolower(accept[i]));
	}
	int c;
	for(char* work = (char*) s; *work != '\0'; ++work)
	{
		c = tolower(*work);
		for(size_t i = 0; i < accept_len; ++i)
		{
			if (c == accept_lower[i])
			{
				return (const char*) work;
			}
		}
	}
	return NULL;
}

int main()
{
	
	char input[1024];
        for(;;)
        {
                printf("Eingabe (nach Leerzeichen wird gesucht): ");

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
		const char* first_space =  BeCstrcichr(input, ' ');
		printf("Ab ersten Leerzeichen: '%s'\n", first_space == NULL ? "KEIN VORKOMMEN" : first_space);
		const char* last_space =  BeCstrrcichr(input, ' ');
		printf("Ab letzem Leerzeichen: '%s'\n", last_space == NULL ? "KEIN VORKOMMEN" : last_space);
		const char* first_vowl =  BeCstrcipbrk(input, "aeiou");
		printf("Ab erstem Vokal:       '%s'\n", first_vowl == NULL ? "KEIN VORKOMMEN" : first_vowl);
	}
}



