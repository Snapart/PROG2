// Carola Berger
// date_help.h
// test

#ifndef __date_help__
#define __date_help__



int is_leap(int year); // ist Schaltjahr - Jahr wird als int benötigt
int days_in_month(int year, int month); // Tagesanzahl im Monat (1 = Januar bis 12 = Dezember) unter Berücksichtigung Schaltjahr
char* name_of_month(int month); // Name des Monats (1 = Januar bis 12 = Dezember)



#endif

