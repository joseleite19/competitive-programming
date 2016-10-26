#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, m, k, c[200005], vis[200005];

vector<int> g[200005];

int bfs(int source){
	map<int, int> hack;
	int ans = 1, tot = 1;

	queue<int> q;
	q.push(source);
	vis[source] = 1;
	hack[ c[source] ]++;

	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int i = 0; i < (int)g[u].size(); i++){
			int v = g[u][i];
			if(!vis[v]){
				tot++;
				vis[v] = 1;
				ans = max(ans, ++hack[ c[v] ]);
				q.push(v);
			}
		}
	}
	return tot - ans;
}

int main(){
	scanf("%d %d %d", &n, &m, &k);

	for(int i = 0; i < n; i++)
		scanf("%d", c+i);

	int l, r;
	for(int i = 0; i < m; i++){
		scanf("%d %d", &l, &r); l--; r--;
		g[l].push_back(r);
		g[r].push_back(l);
	}

	int ans = 0;

	for(int i = 0; i < n; i++){
		if(!vis[i]){
			ans += bfs(i);
		}
	}

	printf("%d\n", ans);

	return 0;
}