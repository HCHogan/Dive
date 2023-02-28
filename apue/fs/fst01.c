#include <unistd.h>
#include <fcntl.h>

int main() {
	write(0, "nmsl\n", 5);
	return 0;
}
