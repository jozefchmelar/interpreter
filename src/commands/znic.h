/*! \file  znic.h
\brief  zničí (odstráni) predmet v danej miestnosti
\author Jozef Chmelar
*/
#include <sys/stat.h>
#include <stdio.h>
/*! \brief deletes file in cwd
@param predmet name of the file to delete
*/
int znic(const  char *predmet)
{
  char buf[1024];
  char cwd[1024];
  char zahodit[1024];
  char fullpath[1024];
  struct stat bufstat;
  ssize_t len;
  strcpy(zahodit, predmet);

  getcwd(cwd, sizeof(buf));
  strcpy(fullpath, cwd);
  strcat(fullpath, "/");
  strcat(fullpath, zahodit);

  lstat(fullpath, &bufstat);
  if (S_ISREG(bufstat.st_mode)) {
    if (unlink(fullpath) != 0) {
      fprintf(stderr, "nemozem vymazat");
    }
    return 0;

  }
  return -1;
}
