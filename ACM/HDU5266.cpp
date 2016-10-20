#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define eps 1e-8
#define INF 0x7fffffff
#define maxn 300010
#define PI acos(-1.0)
#define seed 31//131,1313
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
//DFS + RMQ 在线算法
struct node
{
	int x;
};
vector<node> V[maxn];
int E[maxn * 2], D[maxn * 2], first[maxn], vis[maxn], dis[maxn], n, m, top = 1,root[maxn],st;
int dp[30][maxn * 2];
void init(int n)
{
	top=1;
	memset(root,0,sizeof(root));
	memset(vis,0,sizeof(vis));
	for(int i=1; i<=n; i++)
		V[i].clear();
	int a, b;
	node tmp;
	for (int i = 0; i < n-1; i++)
	{
		scanf("%d%d", &a, &b);
		tmp.x = b;
		V[a].push_back(tmp);
		tmp.x = a;
		V[b].push_back(tmp);
		root[b]=1;
	}
	st = 1;
}
void dfs(int u, int dep)
{
	vis[u] = 1, E[top] = u, D[top] = dep, first[u] = top++;
	for (int i = 0; i < V[u].size(); i++) if (!vis[V[u][i].x])
	{
		int v = V[u][i].x;
		dfs(v, dep + 1);
		E[top] = u, D[top++] = dep;
	}
}
void ST(int num)
{
	for (int i = 1; i <= num; i++) dp[0][i] = i;
	for (int i = 1; i <= log2(num); i++)
		for (int j = 1; j <= num; j++) if (j + (1 << i) - 1 <= num)
		{
			int a = dp[i - 1][j], b = dp[i - 1][j + (1 << i >> 1)];
			if (D[a] < D[b]) dp[i][j] = a;
			else dp[i][j] = b;
		}
}
int RMQ(int x, int y)
{
	int k = (int) log2(y - x + 1.0);
	int a = dp[k][x], b = dp[k][y - (1 << k) + 1];
	if (D[a] < D[b]) return a;
	return b;
}
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		init(n);
		dfs(st, 0);
		ST(top);
		int q;
		scanf("%d", &q);
		while (q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			int a = first[x], b = first[y];
			if (a > b) swap(a, b);
			int pos = RMQ(a, b);
			printf("%d\n",E[pos]);
		}
	}
	return 0;
}