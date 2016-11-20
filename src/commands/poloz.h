
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "settings.h"

int poloz(char *pth) {
  printf("poloz:\t %s\n",pth);
  char vakpath[1024];
  strcpy(vakpath,VAK_PATH);
  strcat(vakpath,pth);
  char cwd[1024];
  getcwd(cwd, sizeof(cwd));
  strcat(cwd,pth);
  
  return cp(vakpath,cwd);



}
