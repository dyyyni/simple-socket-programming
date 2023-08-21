CC=gcc
CFLAGS= -g

all: tcpc

tcpc: tcpClient.c
	$(CC) $(CFLAGS) -o tcpc tcpClient.c

clean:
	rm -rf tcpc
