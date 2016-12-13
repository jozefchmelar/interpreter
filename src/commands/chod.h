/*! \file chod.h
\brief vojde do danej miestnosti 
\author Jozef Chmelar
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

/*! \brief Function to enter into dir or link
  Function checks if directory we want to enter to 
  exits and if so it checks wheter it's a link 
  
*/ 
static inline int chod(const char *pth)
{
    char path[256];
    char buf[1024];
    char cwd[1024];
    char fullpath[2048];
    struct stat bufstat;
    ssize_t len;
    //create path
    getcwd(cwd, sizeof(cwd));
    strcpy(path, pth);
    strcpy(fullpath, cwd);
    strcat(fullpath, "/");
    strcat(fullpath, path);
    lstat(fullpath, &bufstat);
    //check if dir is symbolic link
    //if so read destination change dir.
    if (S_ISLNK(bufstat.st_mode)) {
        if ((len = readlink(fullpath, buf, sizeof(buf) - 1)) != -1) {
            //  buf[len] = '\0';
            if (chdir(buf) == -1) {
                printf("chdir! %s\n", strerror(errno));
            }
            return 0;
        }
    } else {
        if (chdir(path) == 0) {
            return 0;
        } else {
            printf("\tneexistuje\n");
            return 0;
        }
    }
}
