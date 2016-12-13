/*! \file  klonuj.h
\brief  vytvorí kópiu predmetu v danej miestnosti do vaku
\author Jozef Chmelar
*/
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "cp.h"

/*! \brief duplicate file into VAK folder
  @param pth  path of the file to duplicate 
   duplicates a file 
*/ 
static inline int klonuj(const  char *pth)
{
  char path[256];
  char buf[1024];
  char cwd[1024];
  char fullpath[2048];
  struct stat bufstat;
  ssize_t len;

  getcwd(cwd, sizeof(cwd));
  strcpy(path, pth);
  strcpy(fullpath, cwd);
  strcat(fullpath, "/");
  strcat(fullpath, path);
  lstat(fullpath, &bufstat);
  if (!S_ISDIR(bufstat.st_mode)) {
    char newfname[1024];
    char vakPath[256];
    strcpy(vakPath, getenv("HOME"));
    strcat(vakPath, "/VAK/");

    strcpy(newfname,vakPath);
    strcat(newfname, path);

    return cp(fullpath, newfname);
  }
}
 