#include <bits/stdc++.h>

using namespace std;

#define BRANCO 0
#define CINZA 1
#define PRETO 2

bool loop;
int n, m, color[10004];
vector<vector<int> > g;

void dfs(int u){
	if(color[u] == BRANCO){
		color[u] = CINZA;

		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i];
			dfs(v);
		}
	}
	else if(color[u] == CINZA){
		loop = true;
	}

	color[u] = PRETO;
}

int main(){
	int t, a, b;

	scanf("%d", &t);

	while(t--){
		scanf("%d %d", &n, &m);
		g.assign(n+1, vector<int>());
		
		for(int i = 0; i < m; i++){
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
		}

		loop = false;
		memset(color, BRANCO, sizeof color);
		for(int u = 1; u <= n; u++)
			dfs(u);

		printf("%s\n", loop ? "SIM" : "NAO");
	}

	return 0;
}