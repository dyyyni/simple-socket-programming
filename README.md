# simple-socket-programming
Simple web client and server written in C to learn more about socket programming.

## How to build
Make sure you have Make and GCC installed.

```git clone git@github.com:dyyyni/simple-socket-programming.git```

Navigate in to the project directory.

```make```

To remove the build dir when you are done

```make clean```

## tcpc -> tcpClient usage: google.com example

Navigate in to the build directory.

```./tcpc 172.217.19.78```

## tcps -> tcpServer usage

Navigate in to the build directory

```./tcps```

You can visit the server with your browser at: localhost:1800

Or you can use the tcpClient

```./tcpc 127.0.0.0```
