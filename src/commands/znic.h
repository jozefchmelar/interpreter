#include <sys/stat.h>
#include "settings.h"
#include <stdio.h>

int znic (char *predmet) {
  char buf[1024];
  char cwd[1024];
  char zahodit[1024];
  char fullpath[1024];
  struct stat bufstat;
  ssize_t len;
  strcpy(zahodit, predmet);

  printf("znic:\t%s\n", zahodit);
  getcwd(cwd, sizeof(buf));
  strcpy(fullpath, cwd);
  strcat(fullpath, "/");
  strcat(fullpath, zahodit);

  lstat(fullpath, &bufstat);

  if (S_ISREG(bufstat.st_mode)) {
    buf[len] = '\0';
    return unlink(fullpath);
  } 
  return -1;
}