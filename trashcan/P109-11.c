#include <stdio.h>
#include <math.h>

int a[4];

void sort(int a[], int l, int r) {
	if(l >= r) return;
	int i = l, j = r, x = a[l];
	while(i < j) {
		while(i < j && a[j] > x) --j;
		if(i < j) a[i++] = a[j];
		while(i < j && a[i] < x) ++i;
		if(i < j) {
			a[j--] = a[i];
		}
	}
	a[i] = x;
	sort(a, l, i - 1);
	sort(a, i + 1, r);
}

int main() {
	for(int i = 0; i < 4; i++) {
		scanf("%d", a+i);
	}
	sort(a, 0, 3);
	for(int i = 0; i < 4; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
