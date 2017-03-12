#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

vector<int> g[200005];
int n;
int color[200005];

int k;

int dfs(int u, int p){

	int cnt = 1;
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(v == p) continue;
		if(cnt == color[u]) cnt++;
		if(cnt == color[p]) cnt++;
		if(cnt == color[u]) cnt++;
		if(cnt == color[p]) cnt++;
		if(u == 3) printf("|%d %d\n", color[u], color[p]);
		color[v] = cnt++;
		dfs(v, u);
	}
	k = max(k, cnt-1);
}

int main(){
	
	scanf("%d", &n);

	for(int i = 0; i < n-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	color[1] = 1;
	k = 1;

	dfs(1, 0);

	printf("%d\n", k);
	
	for(int i = 1; i <= n; i++)
		printf("%d ", color[i]);
	printf("\n");






	return 0;
}