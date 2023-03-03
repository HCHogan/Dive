#include "./myudp.h"

#define BUFFER_SIZE 512

int main(int argc, char* argv[]) {
	int sd = UDP_Open(2000);
	struct sockaddr_in addr, addr2;
	int rc = UDP_FillSockAddr(&addr, "nmsl", 10000);
	char message[BUFFER_SIZE];
	sprintf(message, "hello");
	rc = UPD_Write(sd, &addr, message, BUFFER_SIZE);
	if(rc > 0) {
		int rc = UPD_Read(sd, &addr2, buffer, BUFFER_SIZE);
	}
	return 0;
}
