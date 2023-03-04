#include <iostream>
#include <algorithm>
#include <memory.h>

const int N = 10010;

struct edge {
	int v, c, ne;
} e[N];

int h[N], d[N], cur[N];
int idx = 1;

void add(int a, int b, int c) {
	e[++idx] = { b, c, h[a] };
	h[a] = idx;
}

bool bfs() {			// 对点分层找增广路
	memset(d, 0, sizeof d);
	
}

int main() {

	return 0;
}
