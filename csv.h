#ifndef INCLUDE_CSV_H
#define INCLUDE_CSV_H

int csvparse(int fd, char ***buf);

int readlnbuf(int fd, char *buf, size_t n);

char *readln(int fd);

int lnparse(char *ln, char **buf);

#endif
