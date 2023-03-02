#include <unistd.h>
#include <linux/udp.h>
#include <linux/if.h>
#include <linux/tcp.h>

int main(int argc, char* argv[]) {
	int sd = UDP_Open(2000);
	struct sockaddr_in addr, addr2;
	int rc = UDP_FillSocket
}
