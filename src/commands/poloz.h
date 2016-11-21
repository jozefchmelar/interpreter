
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "settings.h"

int poloz(const  char *pth)
{
   char vakpath[1024];
  strcpy(vakpath, VAK_PATH);
  strcat(vakpath, pth);
  char cwd[1024];
  getcwd(cwd, sizeof(cwd));
  strcat(cwd, "/");

  strcat(cwd, pth);
// int cp(const char *source, const char *destination)
  cp(vakpath, cwd);
  return unlink(vakpath);
}
