#include "common.h"
#include <string.h>

int main(int argc, char *argv[])
{
  int                 listenfd, connfd, n;
  struct sockaddr_in  servaddr;
  uint8_t             buff[MAXLINE+1];
  uint8_t             recvline[MAXLINE+1];

  if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    err_n_die("socket error.");

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family       = AF_INET;
  servaddr.sin_addr.s_addr  = htonl(INADDR_ANY);
  servaddr.sin_port         = htons(SERVER_PORT);

  if((bind(listenfd, (SA *) &servaddr, sizeof(servaddr))) < 0)
    err_n_die("bind error.");

  if((listen(listenfd, 10)) < 0)
    err_n_die("listen error.");

  for( ; ; )
  {

    // the 'accept()' function blocks the progression of the program
    // until it has returned with a connected client.
    printf("waiting for a connection on port %d\n", SERVER_PORT);
    fflush(stdout);
    connfd = accept(listenfd, (SA *) NULL, NULL);

    // Making sure receive buffer is empty so it gets null terminated.
    memset(recvline, 0 , MAXLINE);

    // Reading the message from the client
    while( (n = read(connfd, recvline, MAXLINE-1) ) > 0)
    {
      fprintf(stdout, "\n%s\n\n%s", bin2hex(recvline, n), recvline);

      if(recvline[n-1] == '\n')
        break;

      memset(recvline, 0, MAXLINE);
    }

    if(n < 0)
      err_n_die("read error");

    // preparing a response
    snprintf((char*) buff, sizeof(buff), "HTTP/1.0 200 OK\r\n\r\n<h1>Hello</h1>");
    // sending it
    write(connfd, (char*) buff, strlen((char*) buff));
    close(connfd);
  }

  return 0;
}
