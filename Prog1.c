// Carola Berger
// Hauptprogramm
// Prog1.c

#ifndef __Berger_h__ // Header wird ebenfalls in BergerCarolaBirth.c verwendet
#define __Berger_h__


#include <stdio.h> // Standardheader
#include "Berger.h" // eigener Header
#include "Carola.h" // eigener Header
#include "BergerCarolaBirth.h" // eigener Header


int main() // main-Funktion
{
        printBerger(); // Aufruf der Funktion aus Berger.c
        printf ("\n\n"); // formatierte Ausgabe mit 2 Zeilenumbrüchen
        printCarola(); // Aufruf der Funktion aus Carola.c
        printf ("\n\n"); // formatierte AUsgabe mit 2 Zeilenumbrüchen
        BergerCarolaBirthDate(); // Aufruf der Funktion aus BergerCarolaBirth.c - enthalt auch die Ausgabe von Berger.c
        printf ("\n"); // formatierte Ausgabe mit Zeilenumbruch
        return 0; //bendet Funktion
}

#endif
