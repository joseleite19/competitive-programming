#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g, normal;

int c, p, vis[1000], L[1000];
bool dp[1000][1000];
int mark[1000][1000], pass;

void dfs(int v){
	vis[v] = pass;
	for(int i = 0; i < (int)normal[v].size(); i++)
		if(vis[ normal[v][i] ] != pass)
			L[ normal[v][i] ] = L[v]+1, dfs( normal[v][i] );
}

bool f(int u, int v){
	if(mark[u][v] == pass) return dp[u][v];
	mark[u][v] = pass;

	if(u == v) return dp[u][v] = (u == 0);

	if(L[u] > L[v]){
		for(int i = 0; i < (int)g[u].size(); i++) if(f(g[u][i], v))
			return dp[u][v] = 1;
	}
	else for(int i = 0; i < (int)g[v].size(); i++) if(f(u, g[v][i]))
		return dp[u][v] = 1;
	return dp[u][v] = 0;
}

int main(){
	int a, b;

	while(scanf("%d %d", &c, &p) == 2){
		pass++;
		g.assign(c, vector<int>());
		normal.assign(c, vector<int>());

		for(int i = 0; i < p; i++){
			scanf("%d %d", &a, &b); a--; b--;
			g[b].push_back(a);
			normal[a].push_back(b);
		}

		L[0] = 1;
		dfs(0);
		int ans = 0;

		for(int i = 0; i < c; i++)
			for(int j = i+1; j < c; j++)
				if(f(i, j))
					ans++;

		printf("%d\n", ans);
	}

	return 0;
}