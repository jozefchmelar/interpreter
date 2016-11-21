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
	mkdir ("/tmp/VAK/", S_IRWXU);	

	for (int i = 1; i < argc; ++i)
	{
		// if command has parameter and parameter of command is not another command execute.
		if (hasParameter(argv[i]) == 0 && isCommand(argv[i + 1]) == 1) {

			if (strcmp("chod", argv[i]) == 0 ) {
				chod(argv[++i]);
			} else if (strcmp("klonuj", argv[i]) == 0 ) {
				klonuj(argv[++i]);
			} else if (strcmp("znic", argv[i]) == 0 ) {
				znic(argv [++i]);
			} else if (strcmp("preskumaj", argv[i]) == 0 ) {
				preskumaj(argv [++i]);
			} else if (strcmp("zober", argv[i]) == 0 ) {
				zober(argv [++i]);
			} else if (strcmp("poloz", argv[i]) == 0 ) {
				poloz(argv  [++i]);
			}
		} else {
			if (strcmp("koniec", argv[i]) == 0 ) {
				koniec();
			} else if (strcmp("hmotnostvaku", argv[i]) == 0 ) {
				hmotnostvaku();
			} else if (strcmp("kdesom", argv[i]) == 0 ) {
				kdesom();
			} else if (strcmp("prezri", argv[i]) == 0 ) {
				prezri();
			} else if (strcmp("cesty", argv[i]) == 0 ) {
				cesty();
			} else if (strcmp("obsahvaku", argv[i]) == 0 ) {
				obsahvaku();
			} else if (isCommand(argv[i])==0){ //this has to be here!
				fprintf(stderr, "syntax error %d:  %s missing parameter\n\n", i, argv[i]);

			} else {
				printf("system command %s\t\n", argv[i]);
				system(argv[i]);
			}
		}

	}	
	koniec();	

	return 0;
}
