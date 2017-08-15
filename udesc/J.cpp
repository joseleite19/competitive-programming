#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
int color[30];
int vis[30];

bool dfs(int u){
	vis[u] = 1;
	// printf("%d %d\n", u, color[u]);

	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(color[v] == 2 || color[v] == 3 || color[v] == 5) continue;
		if(color[v] == color[u]) return false;
		if(vis[v]) continue;

		if(!color[v]){
			if(color[u] == 1) color[v] = 4;
			else color[v] = 1;
		}
		if(!dfs(v)) return false;
	}
	return true;
}

int main(){
	int t;

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		int n, m;

		scanf("%d %d", &n, &m);

		g.assign(n, vector<int>());

		for(int i = 0; i < m; i++){
			char u, v;
			scanf(" %c %c", &u, &v);
			g[u-'A'].push_back(v-'A');
			g[v-'A'].push_back(u-'A');
		}
		int k;

		scanf("%d", &k);

		memset(color, 0, sizeof color);
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < k; i++){
			char c; int v;
			scanf(" %c %d", &c, &v);
			color[c-'A'] = v;
		}

		bool can = true;
		for(int i = 0; i < n; i++)
			if(!vis[i]){
				if(!color[i]){
					color[i] = 1;
					can &= dfs(i);
				}
			}
		printf("calabouco #%d: %s\n\n", tc, can ? "Gabriel e Lucas jogaram este jogo ateh o fim!" : "Gabriel e Lucas NAO completaram este jogo!");
	}

	return 0;
}