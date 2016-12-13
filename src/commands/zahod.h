/*! \file  zahod.h
\brief  zahodí (odstráni) predmet z vaku
\author Jozef Chmelar
*/
#include <sys/stat.h>

/*! \brief deletes file from VAK
@param predmet - name of the file in VAK
*/
int zahod(const  char *predmet)
{
  char buf[1024];
  char zahodit[1024];
  char fullpath[1024];
  struct stat bufstat;
  ssize_t len;
  strcpy(zahodit, predmet);
  strcpy(fullpath, getenv("HOME"));
  strcat(fullpath, "/VAK/");
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
