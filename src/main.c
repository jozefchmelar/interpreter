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

int main (int argc, const char *argv[])
{
	// char *line = NULL;
	// size_t len = 0;
	// ssize_t read = 0;



	while (1 == 1) {
		// read = getline(&line, &len, stdin);
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
		if (hasParameter(command[0]) == 0 && isCommand(command[1]) == 1) {
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
			} else if (isCommand(command[0]) == 0) { //this has to be here!
				fprintf(stderr, "syntax error :  %s missing parameter\n\n",  command[0]);

			} else {	
				system(origcomm);
			}
		}

	}



	// for (int i = 1; i < argc; ++i)
	// {
	// 	// if command has parameter and parameter of command is not another command execute.
	// 	if (hasParameter(argv[i]) == 0 && isCommand(argv[i + 1]) == 1) {

	// 		if (strcmp("chod", argv[i]) == 0 ) {
	// 			chod(argv[++i]);
	// 		} else if (strcmp("klonuj", argv[i]) == 0 ) {
	// 			klonuj(argv[++i]);
	// 		} else if (strcmp("znic", argv[i]) == 0 ) {
	// 			znic(argv [++i]);
	// 		} else if (strcmp("preskumaj", argv[i]) == 0 ) {
	// 			preskumaj(argv [++i]);
	// 		} else if (strcmp("zober", argv[i]) == 0 ) {
	// 			zober(argv [++i]);
	// 		} else if (strcmp("poloz", argv[i]) == 0 ) {
	// 			poloz(argv  [++i]);
	// 		}
	// 	} else {
	// 		if (strcmp("koniec", argv[i]) == 0 ) {
	// 			koniec();
	// 		} else if (strcmp("hmotnostvaku", argv[i]) == 0 ) {
	// 			hmotnostvaku();
	// 		} else if (strcmp("kdesom", argv[i]) == 0 ) {
	// 			kdesom();
	// 		} else if (strcmp("prezri", argv[i]) == 0 ) {
	// 			prezri();
	// 		} else if (strcmp("cesty", argv[i]) == 0 ) {
	// 			cesty();
	// 		} else if (strcmp("obsahvaku", argv[i]) == 0 ) {
	// 			obsahvaku();
	// 		} else if (isCommand(argv[i]) == 0) { //this has to be here!
	// 			fprintf(stderr, "syntax error %d:  %s missing parameter\n\n", i, argv[i]);

	// 		} else {
	// 			printf("system command %s\t\n", argv[i]);
	// 			system(argv[i]);
	// 		}
	// 	}

	// }
	// koniec();

	return 0;
}
