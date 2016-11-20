
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "settings.h"
#include "cp.h"

int klonuj(const  char *pth)
{

  char path[256];
  char buf[1024];
  char cwd[1024];
  char fullpath[2048];
  struct stat bufstat;
  ssize_t len;

  getcwd(cwd, sizeof(cwd));
  strcpy(path, pth);
  printf("klonuj:\t%s\n", path);
  strcpy(fullpath, cwd);
  strcat(fullpath, "/");
  strcat(fullpath, path);
  lstat(fullpath, &bufstat);
  if (!S_ISDIR(bufstat.st_mode)) {
    char newfname[1024];
    strcpy(newfname, VAK_PATH);
    strcat(newfname, path);

    return cp(fullpath, newfname);
  }
}
