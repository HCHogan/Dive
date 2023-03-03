#include <stdio.h>

int main() {
	FILE* fp = fopen("d2.dat", "w");
	int k, n, a[6] = {1, 2, 3, 4, 5, 6};
	fprintf(fp, "%d%d%d\n", a[0], a[1], a[2]);
	fclose(fp);
	fp = fopen("d2.dat", "r");
	fscanf(fp, "%d%d", &k, &n);
	char *s1 = "OK", *s2 = "OK";
}
