#include <sys/stat.h>
#include "settings.h"

int zahod(const  char *predmet)
{
  char buf[1024];
  char zahodit[1024];
  char fullpath[1024];
  struct stat bufstat;
  ssize_t len;
  strcpy(zahodit, predmet);
  printf("zahod:\t%s\n", zahodit);
  strcpy(fullpath, VAK_PATH);
  strcat(fullpath, "/");
  strcat(fullpath, zahodit);
  lstat(fullpath, &bufstat);
  if (S_ISREG(bufstat.st_mode)) {
    buf[len] = '\0';
    return unlink(fullpath);
  } else {
    return 1;
  }
  return 0;
}
