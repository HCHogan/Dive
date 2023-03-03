#include <sys/socket.h>
#include <unistd.h>
#include <linux/udp.h>
#include <linux/if.h>
#include <linux/tcp.h>

int UPD_Write(int sd, struct sockaddr_in *addr, char* hostName, int port) {
	bzero(addr, sizeof(struct sockaddr_in));
	addr->sin_family = AF_INET;
}
