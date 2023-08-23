#ifndef COMMON_H
#define COMMON_H

#include <sys/socket.h>
#include <sys/types.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <netdb.h>
#include <stddef.h>

// Useful constants
// #define SERVER_PORT 80 <-- used for connecting outer web.
#define SERVER_PORT 1800

#define MAXLINE 4096
#define SA struct sockaddr

void err_n_die(const char *fmt, ...);
char *bin2hex(const unsigned char *input, size_t len);

#endif /* COMMON_H */
