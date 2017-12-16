#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int n,m,mat[1003][1003];
int vis[1003][2];
vector<int> adj[1003];

vector<pair<int, pair<int, pair<bool, int> > > > g[1003]; //<vx, peso, de vdd ou virada>

int color[1003];
int tam[1003];
int ans;
int delta[1003];
int p[1003];

set<int> ss;

void dfs(int x, bool podeusarvirada){
	if(vis[x][podeusarvirada]) return;
	vis[x][podeusarvirada] = 1;
	
	for(int i = 0; i < (int)g[x].size(); i++){
		int v = g[x][i].ff;
		int w = g[x][i].ss.ff;
		bool s = g[x][i].ss.ss.ff;
		int id = g[x][i].ss.ss.ss;
		// printf("%d->%d = %d, %d\n", x, v, w, id);
		if(!podeusarvirada && s == 0) continue;

		if(vis[v][1] == 1 || vis[v][0] == 1){ // achei ciclo
			int tmp = delta[x] - delta[v] + w;
			// if(id == 2) printf("%d %d %d\n", delta[x], delta[ v ], w);
			if(tmp > ans){
				ans = tmp;
				ss.clear();
				ss.insert(id);
				// printf("..%d %d\n", id, ans);
			}
			else if(tmp == ans){
				// printf("..%d %d\n", id, ans);
				ss.insert(id);
			}
		}
		if(vis[v][s] == 0){
			if(vis[x][!s] == 2) continue;
			int tmp = delta[x] + w;
			// delta[x] += w;
			delta[v] += tmp;
		// printf("%d->%d %d, %d:%d\n", x, v, w, delta[v], vis[v][s] == 1);
			p[v] = x;
			dfs(v, s);
			// delta[x] -= w;
			delta[v] -= tmp;
		}
		
	}

	vis[x][podeusarvirada] = 2;
}

vector<int> num, low, S, visited;
int numSCC, dfsNumberCounter;



void tarjanSCC(int u) {
	low[u] = num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	for(int j = 0; j < (int)adj[u].size(); j++){
		int v = adj[u][j];
		if(num[v] == -1)
			tarjanSCC(v);
		if(visited[v])
			low[u] = min(low[u], low[v]);
	}

	if (low[u] == num[u]){
		++numSCC;
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			color[v] = numSCC;
			tam[ color[v] ]++;
			if (u == v) break;
		}
	}
}

vector<int> zxc[1003];

int main(){
   // file();
    
	scanf("%d %d",&n,&m);
	map<pair<int, int>, int> asd;
	for(int i = 0; i < m; i++){
		int s,v;
		scanf("%d %d",&s,&v);
		adj[s].pb(v);
		asd[ mp(s, v) ] = i+1;
	}


	num.assign(n+1, -1); low.assign(n+1, 0); visited.assign(n+1, 0);
	dfsNumberCounter = numSCC = 1;
	for (int i = 1; i <= n; i++){
		if(num[i] == -1)
			tarjanSCC(i);
	}

	// for(int i = 1; i <= n; i++)
	// 	printf(".%d %d %d\n", i, color[i], tam[ color[i] ] );

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < (int)adj[i].size(); j++){
			int v = adj[i][j];
			if(color[i] != color[v] && !mat[ color[i] ][ color[v] ]){
				g[ color[i] ].push_back(mp(color[v], mp(tam[ color[v] ], mp(1, asd[ mp(i, v)]))));
				g[ color[v] ].push_back(mp(color[i], mp(tam[ color[i] ], mp(0, asd[ mp(i, v)]))));
				// printf("%d->%d = %d:%d.\n", color[i], color[v], tam[ color[v] ], asd[ mp(i, v)]);
				// printf("%d->%d = %d\n", color[v], color[i], tam[ color[i] ]);
				mat[ color[i] ][ color[v] ] = 1;
				mat[ color[v] ][ color[i] ] = 1;
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < (int)adj[i].size(); j++){
			int v = adj[i][j];
			if(color[i] == color[v])
				zxc[ color[i] ].push_back(asd[ mp(i, v)]);
		}
	}





	for(int i = 1; i <= n; i++){
		if(!vis[ color[i] ][1]){
			// delta[ color[i] ] = tam[ color[i] ];
			if(tam[ color[i] ] > ans){
				ans = tam[ color[i] ];
				for(int j = 0; j < (int)zxc[ color[i] ].size(); j++)
					ss.insert(zxc[ color[i] ][j]);
			}
			else if(tam[ color[i] ] == ans){
				for(int j = 0; j < (int)zxc[ color[i] ].size(); j++)
					ss.insert(zxc[ color[i] ][j]);
			}
			
			dfs(color[i], 1);
			// delta[ color[i] ] = 0;

		}
	}


	printf("%d\n", ans);

	printf("%d\n", (int)ss.size());

	for(set<int>::iterator it = ss.begin(); it != ss.end(); it++)
		printf(" %d", *it);
	printf("\n");





	return 0;
}