#include <iostream>
#include <queue>
#include <memory.h>
#include <algorithm>
// f(x, y) <= c(x,y)
// 所有流向x的流量等于所有流向v的流量
// 最大流:从原点流向汇点的最大流量
// 增广路一条从原点到汇点的所有边的剩余容量>=0 的路径
// 残留网:由网络中所有节点和剩余容量大于0的边构成的子图,包括有向边和其反向边

using namespace std;

typedef long long LL;

const int N = 10010;

struct edge {
	LL v,c,ne;
} e[N];

int S, T, n;
LL head[N], mf[N];			// max flow
int pre[N];
int idx = 1;				// 从2, 3开始配对
							// 0 作为边界判断
void add(int a, int b, int c) {
	e[++idx] = { b, c, head[a] };
	head[a] = idx;
}

bool bfs() {
	memset(mf, 0, sizeof(mf));
	queue<int> q;
	q.push(S);
	mf[S] = 0x3f3f3f3f;			// 起始点不限流
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = head[u]; i; i = e[u].ne) {
			LL v = e[i].v;
			if(mf[v] == 0 && e[i].c) {
				mf[v] = min(mf[u], e[i].c);
				pre[v] = i;
				q.push(v);
				if(v == T) return true;
			}
		}
	}
	return false;
}

LL EK() {						// 累加可行流
	LL flow = 0;
	while(bfs()) {
		int v = T;
		while(v != S) {			// 更新残留网
			int i = pre[v];		// 前驱边
			e[i].c -= mf[T];
			e[i^1].c += mf[T];
			v = e[i^1].v;		// 回去
		}
		flow += mf[T];
	}
	return flow;
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
		add(y, x, 0);
	}
	printf("%lld\n", EK());
}
