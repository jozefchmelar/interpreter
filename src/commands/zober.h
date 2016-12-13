/*! \file  zober.h
\brief  zoberie predmet z danej miestnosti
\author Jozef Chmelar
*/
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

/*! \brief copy file to VAK path
	creates a copy of file in VAK and after that it removes it  from cwd.
*/
int zober(const  char *predmet)
{
	printf("\n\t");
	klonuj(predmet);
	return znic(predmet);
}
