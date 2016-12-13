/*! \file  poloz.h
\brief  uloží predmet z vaku do aktuálnej miestnosti
\author Jozef Chmelar
*/
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
/*! \brief takes a file form VAK folder and moves it into cwd
  
*/ 
static inline int poloz(const  char *pth)
{
  char *vakpath=getVakPath();
  strcat(vakpath, "/");
  char cwd[1024];
  getcwd(cwd, sizeof(cwd));
  strcat(cwd, "/");
  strcat(cwd, pth);
  // int cp(const char *source, const char *destination)
  cp(vakpath, cwd);
  printf("%s\n", vakpath);
  return unlink(vakpath);
}
