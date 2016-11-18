
#include <dirent.h> 
#include <stdio.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int prezri()
{
  DIR *d;
  struct dirent *dir;  
  struct stat buf;
  d = opendir(".");
  int x;
  int pocet_veci=0;
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      if(dir->d_name[0]!='.' && ! S_ISLNK(buf.st_mode) && ! S_ISDIR(buf.st_mode)){
       x= lstat(dir->d_name,&buf);        
              printf("%s ",dir->d_name);   
              pocet_veci++;        
      }
    }
    if(pocet_veci==0){
      printf("nothing\n");
    }
    closedir(d);
  }
  return(1);
}
