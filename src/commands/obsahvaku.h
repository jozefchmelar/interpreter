#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include "settings.h"

int obsahvaku()
{
	char cwd[1024];
	//create path
	getcwd(cwd, sizeof(cwd));
	printf("Obsah vaku:\t\n");
	chdir(VAK_PATH);
	printf("\t");
	prezri();
	chdir(cwd);
	return 0;
}