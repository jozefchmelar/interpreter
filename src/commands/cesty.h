#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include <unistd.h>
#include <string.h>

int cesty() {
  printf("cesty:\t");
  DIR *d;
  struct dirent *dir;
  struct stat buf;
  int x;
  d = opendir(".");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      if (dir->d_name[0] != '.')
      {
        x = lstat(dir->d_name, &buf);
        if (S_ISLNK(buf.st_mode) || S_ISDIR(buf.st_mode))
        {
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