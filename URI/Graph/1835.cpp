#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int> > g;

vector<bool> visited;

void dfs(int u){
	visited[u] = true;
	for(int v : g[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

int main(){
	int T;

	scanf("%d", &T);

	for(int t = 1; t <= T; t++){
		scanf("%d %d", &n, &m);
		g.assign(n+1, vector<int>());
		visited.assign(n+1, false);
		for(int i = 0; i < m; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		int comp = 0;
		for(int i = 1; i <= n; i++){
			if(!visited[i]){
				comp++;
				dfs(i);
			}
		}
		printf("Caso #%d: ", t);
		if(comp == 1) printf("a promessa foi cumprida\n");
		else printf("ainda falta(m) %d estrada(s)\n", comp-1);
	}

	return 0;
}