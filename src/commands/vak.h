#include <stdlib.h>
#include <dirent.h> 
#include <stdio.h> 
#include <assert.h>
#include <string.h>


int endsWith(const char *filename, const char *ext) {
    const uint len = strlen(filename);
    const uint extLen = strlen(ext);
    if (len < extLen) {
        return 0;
    }
    for (uint index  = 1; index <= extLen; index++) {
        if (filename[len - index] != ext[extLen - index]) {
            return 0;
        }
    }
    return 1;
}

int obsah()   
{
  DIR *d;
  struct dirent *dir;  
  d = opendir(".");
  char *prev;
  prev =getcwd(prev,0);
  chdir(prev);
  if(endsWith(prev, "/svet/batoh")==1){
    printf("ok");
  }
    chdir(prev);
  if(endsWith(prev, "/svet/batoh")==1){
    printf("ok");
  }
    chdir(prev);
  if(endsWith(prev, "/svet/batoh")==1){
    printf("ok");
  }
  d= opendir(".");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      if(dir->d_name[0]!='.')
      printf("%s ", dir->d_name);

    }
	printf("\n");
    closedir(d);
  }

  return(0);
}
