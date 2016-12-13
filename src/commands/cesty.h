/*! \file cesty.h
\brief vypíše zoznam miestností, kam môžeme z aktuálnej miestnosti ísť
\author Jozef Chmelar
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

/*! \brief prints  folders or links that we can go to
  function tries to open directory "d" if it's not null
  it's going to check every single dir within folder and 
  print name of every single directory or symbolic link 
*/ 
static inline int cesty()
{
  DIR *d;
  struct dirent *dir;
  struct stat buf;
  int x;
  d = opendir(".");
  //id d is not null
  if (d) {
    //checks if folder is real folder or just symbolic link.
    while ((dir = readdir(d)) != NULL) {
      if (dir->d_name[0] != '.') {
        x = lstat(dir->d_name, &buf);
        if (S_ISLNK(buf.st_mode) || S_ISDIR(buf.st_mode)) {
          printf("%s ", dir->d_name);
        }
      }
    }
    printf("\n");
    closedir(d);
    return 0;
  } else
    return (1);
}

/*! \brief prints  current working directory
*/ 
int kdesom()
{
  char cwd[1024];
  //create path
  getcwd(cwd, sizeof(cwd));
  printf("%s\n", cwd);
  return 0;
}
