
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "settings.h"

int zober(char *predmet) {
	printf("zober:\t%s",predmet );
	printf("\n\t" );
    klonuj(predmet);
	printf("\t");    
    znic(predmet);
    return 0;
  }