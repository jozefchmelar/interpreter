/*! \file  obsahvaku.h
\brief  vypíše obsah vaku
\author Jozef Chmelar
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
/*! \brief gets VAK path
  returns path of the VAK folder 
  because VAK is located in users folder. 
*/ 
static inline  char* getVakPath(){
	static char path[256];
    strcpy(path, getenv("HOME"));
    strcat(path, "/VAK");
    return path;
}
/*! \brief files in VAK
  funcion saves cwd ,enters VAK folder, prints every file and returns into previous dir.
*/ 
static inline int obsahvaku()
{
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
 	chdir(getVakPath());
	prezri();
	chdir(cwd);
	return 0;
}