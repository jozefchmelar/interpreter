#include <sys/sendfile.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int cp(const char *source, const char *destination)
{

  int input, output;
  if ((input = open(source, O_RDONLY)) == -1) {
    return -1;
  }
  if ((output = open(destination, O_WRONLY | O_CREAT)) == -1) {
    close(input);
    return -1;
  }
  off_t bytesCopied = 0;
  struct stat fileinfo = { 0 };
  fstat(input, &fileinfo);
  int result = sendfile(output, input, &bytesCopied, fileinfo.st_size);
  close(input);
  close(output);

  //set permisions
  char mode[] = "0644";
  int i = strtol(mode, 0, 8);
  if (chmod(destination, i) < 0) {
    fprintf(stderr, "error in chmod %s", strerror(errno));
  }
  return result;
}
