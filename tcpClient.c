#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>

// Default http server
#define SERVER_PORT 80

#define MAXLINE 4096

void err_n_die(const char *fmt, ...);


int main(int argc, char *argv[])
{
  if(argc != 2) err_n_die("usage: %s <server address>", argv[0]);

 return 0;
}


void err_n_die(const char *fmt, ...)
{
  int errno_save;
  va_list     ap;

  errno_save = errno;

  va_start(ap, fmt);
  vfprintf(stdout, fmt, ap);
  fprintf(stdout, "\n");
  fflush(stdout);

  if(errno_save != 0)
  {
    fprintf(stdout, "(errno = %d) : %s\n", errno_save, strerror(errno_save));
    fprintf(stdout, "\n");
    fflush(stdout);
  }
  va_end(ap);

  exit(1);
}
