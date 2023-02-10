#include <stdlib.h>
int volatile main() {
	int* p = NULL;
	free(p);
	return 0;
}
