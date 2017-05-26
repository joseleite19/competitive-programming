#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int color[300005];
vector<pair<int, int> > g[300005];
int p[300005];
int n, k, d;

int ans[300005];

void bfs(){
	queue<int> q;
	for(int i = 0; i < k; i++){
		if(!color[ p[i] ]){
			color[ p[i] ] = i+1;
			q.push(p[i]);
		}
	}

	while(!q.empty()){
		int u = q.front(); q.pop();

		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i].ff, id = g[u][i].ss;
			if(!color[v]){
				color[v] = color[u];
				q.push(v);
			}
			else if(color[v] != color[u]){
				ans[id] = 1;
			}
		}
	}
}

int main(){

	scanf("%d %d %d", &n, &k, &d);

	for(int i = 0; i < k; i++)
		scanf("%d", p+i);

	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(mp(v, i));
		g[v].push_back(mp(u, i));
	}

	bfs();

	int cnt = 0;

	for(int i = 1; i < n; i++)
		if(ans[i])
			cnt++;

	printf("%d\n", cnt);

	for(int i = 1; i < n; i++)
		if(ans[i])
			printf("%d ", i);
	printf("\n");


	return 0;
}