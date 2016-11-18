#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void  cesty(){

    DIR           *d;
    struct dirent *dir;
    struct stat buf;
    int x;
  d = opendir(".");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      if(dir->d_name[0]!='.')
      {
          x= lstat(dir->d_name,&buf);
		  if(S_ISLNK(buf.st_mode))
          {
             printf("%s ",dir->d_name);
          }
      }

    }
    closedir(d);
    printf("\n ");
  }
}
