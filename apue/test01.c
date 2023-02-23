#include <stdio.h>
#include <stdlib.h>
int main() {
	while(1) {
		if(malloc(1000)==NULL)
			break;
	}
	return 0;
}
