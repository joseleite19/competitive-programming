#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, m, t, s, g, h;

vector<vector<pair<int, int> > > G;
vector<vector<int> > dag;
vector<vector<int> > l;

int vis[2003];
int dest[2003];
long long d[2003];

void dijkstra(){

	for(int i = 1; i <= n; i++) d[i] = 1000000000000000000;

	priority_queue<pair<long long, int> > q;
	d[s] = 0;
	q.push(mp(0, s));

	while(!q.empty()){
		int u = q.top().ss;
		long long p = -q.top().ff; q.pop();

		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i].ff;
			long long w = G[u][i].ss;

			if(d[u] + w < d[v]){
				l[v].clear();
				l[v].push_back(u);
				d[v] = d[u] + w;
				q.push(mp(-d[v], v));
			}
			else if(d[u] + w == d[v])
				l[v].push_back(u);
		}
	}
}

void dfs(int u){
	vis[u] = 1;

	for(int v : dag[u])
		if(!vis[v])
			dfs(v);
}

int main(){
	int tc;

	scanf("%d", &tc);

	while(tc--){

		scanf("%d %d %d", &n, &m, &t);
		G.assign(n+1, vector<pair<int, int> >());
		l.assign(n+1, vector<int>());
		dag.assign(n+1, vector<int>());
		
		scanf("%d %d %d", &s, &g, &h);

		for(int i = 0; i < m; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			G[u].push_back(mp(v, w));
			G[v].push_back(mp(u, w));
		}

		for(int i = 0; i < t; i++)
			scanf("%d", dest+i);
		sort(dest, dest+t);

		memset(vis, 0, sizeof vis);
		memset(d, 0, sizeof d);

		dijkstra();

		int qual = 1;

		for(int v = 1; v <= n; v++){
			for(int u : l[v]){
				dag[u].push_back(v);
				if(u == g && v == h) qual = 1;
				if(u == h && v == g) qual = 2;
				// printf("%d->%d\n", u, v);
			}
		}

		if(qual == 1) dfs(h);
		else dfs(g);

		bool first = true;

		for(int i = 0; i < t; i++){
			if(vis[ dest[i] ]){
				if(!first) printf(" ");
				first = false;
				printf("%d", dest[i]);
			}
		}
		printf("\n");
	}



	return 0;
}