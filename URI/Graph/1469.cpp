#include <bits/stdc++.h>

using namespace std;

int n, m, I;
int age[505];
int line[505];
bool visited[505];
vector<vector<int> > g;
#define INF 100000000
int dfs(int u){
	visited[u] = true;
	int ans = age[u];
	for(int v : g[u])
		if(!visited[v])
			ans = min(ans, dfs(v));
	return ans;
}

int main(){

	while(scanf("%d %d %d", &n, &m, &I) == 3){
		g.assign(n, vector<int>());
		for(int i = 0; i < n; i++){
			scanf("%d", age + i);
			line[i] = i;
		}
		for(int i = 0; i < m; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			g[y-1].push_back(x-1);
		}
		for(int i = 0; i < I; i++){
			char c;
			int a, b;
			scanf(" %c", &c);
			if(c == 'T'){
				scanf("%d %d", &a, &b);
				swap(line[a-1], line[b-1]);
				swap(age[line[a-1]], age[line[b-1]]);
			}
			else{
				scanf("%d", &a);
				memset(visited, 0, sizeof visited);
				int ans = INF;
				for(int u : g[ line[a-1] ])
					ans = min(ans, dfs(u));
				if(ans == INF) printf("*\n");
				else printf("%d\n", ans);
			}
		}
	}

	return 0;
}