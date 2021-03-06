/*! \file  prezri.h
\brief  zobrazí zoznam predmetov v aktuálnej miestnosti
\author Jozef Chmelar
*/
#include <dirent.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
/*! \brief prints all dir or symbolic link names 
*/ 
static inline int prezri()
{
  DIR *d;
  struct dirent *dir;
  struct stat buf;
  int x;
  d = opendir(".");
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      if (dir->d_name[0] != '.') {
        x = lstat(dir->d_name, &buf);
        if (S_ISREG(buf.st_mode)) {
          printf("%s ", dir->d_name);
        }
      }
    }
    printf("\n");
    closedir(d);
    return 0;
  } else
    return 1;
}
