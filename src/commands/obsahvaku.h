#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include "settings.h"


int  obsahvaku() {
	printf("Obsah vaku:\t\n");
	chdir(VAK_PATH);
	printf("\t");
	prezri();
	return 0;
}





