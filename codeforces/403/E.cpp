#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

vector<int> g[200005];
int n, m, k;

int ans[400005];
int t;

int vis[200005];

int dfs(int u){

	vis[u] = 1;
	// ans[t++] = u;

	int cnt = 0;
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(vis[v]) continue;
		cnt++;
		ans[t++] = v;
		dfs(v);
		ans[t++] = u;
	}
	// if(cnt) ans[t++] = u;
	return cnt;
}

int main(){

	scanf("%d %d %d", &n, &m, &k);

	for(int i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		if(u == v) continue;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	ans[t++] = 1;
	dfs(1);

	int limit = (2*n+k-1) / k;

	int ptr = 0;
	for(int q = 0; q < k; q++){
		int left = max(1, min(t - ptr - (k-q), limit));
		printf("%d", left);
		while(left--) printf(" %d", ans[ptr++]);
		printf("\n");
	}


	return 0;
}