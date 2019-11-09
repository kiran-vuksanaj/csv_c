#include<stdio.h>
#include<stdlib.h>

#include<unistd.h>
#include<errno.h>

#include<string.h>

#include"csv.h"

char *readln(int fd) {
  size_t size = 16;
  size_t read_sofar = 0;
  char *buf = malloc(16);
  int lnsize = readlnbuf(fd,buf,size);
  while( lnsize < 0 ) {
    if( lnsize == -1 ) {
      free(buf);
      return NULL;
    }
    read_sofar = size;
    size = size << 1;
    buf = realloc(buf,size);
    lnsize = readlnbuf(fd,buf + read_sofar ,size + read_sofar);
  }
  // resize buffer down to wherever we ended up actually reaching
  buf = realloc(buf,lnsize);
  return buf;
}

int readlnbuf(int fd, char *buf, size_t n) {
  // this! is! probably! really! stupid!
  // idk how costly read() is but its probably best not to pass 1 into it every time
  // i also dk whether it makes sense to go for read(n) instead
  // it feels like it cooould be really inefficient?
  // someone pls tell me

  size_t c;
  int status;
  for( c = 0; c < n; c++ ) {
    status = read(fd,buf + c,1);
    if(status == -1) return status;
    if(status == 0 || buf[c] == '\n') {
      buf[c] = '\0';
      return c; // this means we've reached EOF, or newline!
    }
  }
  return -2; // non-file error: n is less than the length of the line
}
