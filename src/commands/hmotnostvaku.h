#include <dirent.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "settings.h"

int hmotnostvaku()
{

//save dir location
  char pwd[1024];
  getcwd(pwd, sizeof(pwd));
//change dir.
  chdir(VAK_PATH);
  DIR *d;
  struct dirent *dir;
  struct stat buf;
  int x;
  d = opendir(".");
  if (d) {
    long hmot_vaku = 0;
    while ((dir = readdir(d)) != NULL) {
      if (dir->d_name[0] != '.') {
        x = lstat(dir->d_name, &buf);
        if (S_ISREG(buf.st_mode))       //is regular file.
        {
          hmot_vaku += buf.st_size;
        }
      }
    }
    printf("hmotnost vaku:\t %ldg\n", hmot_vaku);
    closedir(d);
    return chdir(pwd);
  } else
    return 1;
}
