#include<stdio.h>
#include<stdlib.h>

#include<fcntl.h>
#include<errno.h>
#include<string.h>

#include"csv.h"

int main() {
  int fd = open("testfile.txt",O_RDONLY);
  if(fd == -1) {
    printf("error during file open, #%d: %s\n",errno,strerror(errno));
    return 1;
  }
  char *line = readln(fd);
  while(line) {
    printf("[%s]\n",line);
    free(line);
    line = readln(fd);
  }
  return 0;
}
