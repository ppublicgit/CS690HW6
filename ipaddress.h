#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void check_host_name(int hostname);

void check_host_entry(struct hostent * hostentry);

void IP_formatter(char *IPbuffer);

char *get_IP();
