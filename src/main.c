/**
@mainpage Interpreter príkazov 
@author Jozef Chmelar

Vytvorte jednoduchý interpreter príkazov v jazyku C, ktorý bude prechádzanie súborovým systémom prezentovať formou putovania hráča virtuálnym svetom. Jednotlivé adresáre predstavujú miestnosti, do ktorých sa dá vstúpiť a obsahujú predmety, reprezentované súbormi. Ako dvere na prechod medzi miestnosťami slúžia symbolické linky[2], ktoré odkazujú na iné adresáre. Predmety (súbory ktorých veľkosť v bytoch vyjadruje hmotnosť v gramoch) sa dajú ukladať do vaku (s obmedzenou nosnosťou) a neskôr odkladať v iných miestnostiach. Príkazy, ktoré váš interpreter príkazov nepozná, spracuje pomocou zavolania interpretera príkazov bash. Zoznam príkazov:

    chod - vojde do danej miestnosti
    zober - zoberie predmet z danej miestnosti
    poloz - uloží predmet z vaku do aktuálnej miestnosti
    obsahvaku - vypíše obsah vaku
    hmotnostvaku - vypíše súčet hmotnosti (veľkosti v bytoch) predmetov vo vaku
    prezri - zobrazí zoznam predmetov v aktuálnej miestnosti
    cesty - vypíše zoznam miestností, kam môžeme z aktuálnej miestnosti ísť
    klonuj - vytvorí kópiu predmetu v danej miestnosti do vaku
    zahod - zahodí (odstráni) predmet z vaku
    znic - zničí (odstráni) predmet v danej miestnosti
    preskumaj - popise daný predmet
    koniec - ukončí činnosť interpretra príkazov
    Pre prezentáciu práce vytvorte svoj vlastný virtuálny svet pozostávajúci z aspoň piatich virtuálnych miestností a niekoľko predmetov.

*/

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

#include "commands/chod.h"
#include "commands/prezri.h"
#include "commands/cesty.h"
#include "commands/klonuj.h"
#include "commands/zahod.h"
#include "commands/znic.h"
#include "commands/preskumaj.h"
#include "commands/obsahvaku.h"
#include "commands/zober.h"
#include "commands/koniec.h"
#include "commands/hmotnostvaku.h"
#include "commands/poloz.h"
#include "commands/util.h"
#define forever while(1)

int main (int argc, const char *argv[])
{
  
	mkdir(getVakPath(),S_IRWXU);

	forever{	
		printf("%s@FRInterpreter # ",getUserName());
		
		char *eof;
		char line[1024];	
		fgets(line, sizeof line, stdin);			
	  	char origcomm[sizeof line];
	  	strcpy(origcomm,line);
		char **command;
		command = split(line);


		size_t ln = strlen(command[0]) - 1;
		if (*command[0] && command[0][ln] == '\n')
			command[0][ln] = '\0';

		// if command has parameter and parameter of command is not another command execute.
		if (hasParameter(command[0]) == 0 && isCommand(command[1]) == 1 ) {
			ln = strlen(command[1]) - 1;

			if (*command[1] && command[1][ln] == '\n')
				command[1][ln] = '\0';

			if (strcmp("chod", command[0]) == 0 ) {
				chod(command[1]);
			} else if (strcmp("klonuj", command[0]) == 0 ) {
				klonuj(command[1]);
			} else if (strcmp("znic", command[0]) == 0 ) {
				znic(command[1]);
			} else if (strcmp("preskumaj", command[0]) == 0 ) {
				preskumaj(command[1]);
			} else if (strcmp("zober", command[0]) == 0 ) {
				zober(command[1]);
			} else if (strcmp("poloz", command[0]) == 0 ) {
				poloz(command[1]);
			}else if (strcmp("zahod", command[0]) == 0 ) {
				zahod(command[1]);
			}
		} else {
			if (strcmp("koniec", command[0]) == 0 ) {
				koniec();
			} else if (strcmp("hmotnostvaku", command[0]) == 0 ) {
				hmotnostvaku();
			} else if (strcmp("kdesom", command[0]) == 0 ) {
				kdesom();
			} else if (strcmp("prezri", command[0]) == 0 ) {
				prezri();
			} else if (strcmp("cesty", command[0]) == 0 ) {
				cesty();
			} else if (strcmp("obsahvaku", command[0]) == 0 ) {
				obsahvaku();
			}else if (strcmp("help", command[0]) == 0 ) {
				help();
			} else if (isCommand(command[0]) == 0) { //this has to be here!
				fprintf(stderr, "syntax error :  %s missing parameter\n",  command[0]);
			} else {	
				system(origcomm);
			}
		}
	}

	return 0;
}

