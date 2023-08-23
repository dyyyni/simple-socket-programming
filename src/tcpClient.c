#include "common.h"

int main(int argc, char *argv[])
{
  int       sockfd, n;
  int       sendbytes;
  struct sockaddr_in  servaddr;
  char      sendline[MAXLINE];
  char      recvline[MAXLINE];

  if(argc != 2) err_n_die("usage: %s <server address>", argv[0]);

  if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    err_n_die("Error while creating the socket!");

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port   = htons(SERVER_PORT);

  // Converts the text presentation of the IP address to binary
  if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    err_n_die("inet_pton error for &s ", argv[1]);
  
  // attempt connection
  if(connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0 )
    err_n_die("connect failed!");

  // prepare a message
  sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");
  sendbytes = strlen(sendline);

  // write the message in to the socket
  if(write(sockfd, sendline, sendbytes) != sendbytes)
    err_n_die("write error");

  memset(recvline, 0, MAXLINE);
  // Read the server response
  while((n = read(sockfd, recvline, MAXLINE-1)) > 0)
  {
    printf("%s", recvline);
  }
  if(n < 0)
    err_n_die("read error");

  return 0;
}
