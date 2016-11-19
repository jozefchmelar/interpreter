#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#include <errno.h>
int chod(char *pth){

    char path[256];
    char buf[1024];
    char cwd[1024];
    char fullpath[2048];
    struct stat bufstat;
    ssize_t len;

    getcwd(cwd,sizeof(cwd));
    strcpy(path,pth);
    strcpy(fullpath,cwd);
    strcat(fullpath,"/");
    strcat(fullpath,path);

    lstat(fullpath,&bufstat);
    if(S_ISLNK(bufstat.st_mode)){
        if ((len=readlink(fullpath, buf, sizeof(buf)-1)) != -1){
            buf[len] = '\0';
            if(chdir(buf)==-1) {
                printf("chdir! %s\n", strerror(errno));
            } 
            return 0;
        }

        }else
        {
            return chdir(path);
        }
    
  printf("\n");
}
