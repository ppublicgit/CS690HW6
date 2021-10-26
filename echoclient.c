/*
 * echoclient.c - An echo client
 */
/* $begin echoclientmain */
#include "csapp.h"
#include "ipaddress.h"

int main(int argc, char **argv)
{
  int clientfd;
  char *host, *port, buf[MAXLINE], ip[MAXLINE];
  rio_t rio;

  if (argc != 3) {
	fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
	exit(0);
  }
  host = argv[1];
  port = argv[2];

  clientfd = Open_clientfd(host, port);
  Rio_readinitb(&rio, clientfd);

  while (Fgets(buf, MAXLINE, stdin) != NULL) {
    // Send ip information in call
    strcpy(ip, "Client IP (");
    strcat(ip, get_IP());
    strcat(ip, ") sent: ");
    strcat(ip, buf);
    Rio_writen(clientfd, ip, strlen(buf)+strlen(ip));
	Rio_readlineb(&rio, buf, MAXLINE);
	Fputs(buf, stdout);
  }
  Close(clientfd);
  exit(0);
}
/* $end echoclientmain */
