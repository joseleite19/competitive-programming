#include <bits/stdc++.h>

using namespace std;

int vis[20020], source = 20018, target = 20019, mat[20020][20020];
int p[20020];

void back(int u){
	if(u == source) return;
	back(p[u]);
	mat[ p[u] ][u]--;
	mat[u][ p[u] ]++;
}

vector<int> g[20020];

int maxflow(){
	int mf = 0;

	while(1){
		memset(vis, 0, sizeof vis);

		vis[source] = 1;
		p[source] = source;

		queue<int> q;
		q.push(source);

		while(!q.empty()){
			int u = q.front(); q.pop();

			if(u == target) break;

			for(int i = 0; i < g[u].size(); i++){
				int v = g[u][i];
				// printf("..%d %d\n", u, v);
				if(mat[u][v] > 0 && vis[v] == 0){
					vis[v] = 1;
					p[v] = u;
					q.push(v);
				}
			}
		}

		if(vis[target] != 1) break;

		back(target);

		mf++;
	}
	return mf;
}

int main(){
	int n, m, a, b;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		g[source].push_back(i);
		mat[source][i] = 1;
		g[10001+i].push_back(target);
		mat[10001 + i][target] = 1;
	}
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);

		g[a].push_back(10001 + b);
		g[10001 + b].push_back(a);
		mat[a][10001 + b] = 1;
	}
	int ret = maxflow();
	printf("%s\n", ret == n ? "YES" : "NO");
}