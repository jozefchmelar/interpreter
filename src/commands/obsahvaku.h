#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include "settings.h"

static inline int obsahvaku()
{
	char cwd[1024];
	//create path
	getcwd(cwd, sizeof(cwd));
 	chdir(VAK_PATH);
	printf("\t");
	prezri();
	chdir(cwd);
	return 0;
}