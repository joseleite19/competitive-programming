#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

vector<int> g[200005];

int color[200005];

int dfs(int u, int c, int p){
	int ret = 0;
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(v == p) continue;

		if(color[v] != c && color[u] == c) ret++;
		ret += dfs(v, c, u);
	}
	return ret;
}

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", color+i);

	int u, v;
	for(int i = 0; i < n-1; i++){
		scanf("%d %d", &u, &v); u--; v--;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	int a = 0, b = 0;
	
	a = dfs(0, color[0], 0);
	b = 1+dfs(0, !color[0], 0);

	printf("%d\n", min(a, b));

	return 0;
}