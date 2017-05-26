#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

vector<vector<pair<int, int> > > g;
int a, b, m, l, k;

int dist[105][505][20];
int vis[105][505][20];

int pass;

int dijkstra(){
	pass++;
	for(int i = 0; i < 105; i++)
		for(int j = 0; j < 505; j++)
			for(int q = 0; q < 20; q++)
				dist[i][j][q] = 1000000000;

	priority_queue<pair<int, pair<int, pair<int, int> > > > q; // dist, rest, k, u

	dist[a+b][0][k] = 0;
	q.push(mp(0, mp(0, mp(k, a+b))));

	int ans = 1000000000;
	while(!q.empty()){
		int d = -q.top().ff;
		int r = q.top().ss.ff;
		int c = q.top().ss.ss.ff;
		int u = q.top().ss.ss.ss; q.pop();
		if(u == 1) ans = min(ans, d);
		if(d > dist[u][r][c]) continue;

		for(pair<int, int> t : g[u]){
			int v = t.ff, w = t.ss;
			if(v > a){ // v é castelo
				if(l >= w && c > 0){ // start jump
					if(dist[v][0][c-1] > dist[u][r][c]){
						dist[v][0][c-1] = dist[u][r][c];
						q.push(mp(-dist[v][0][c-1], mp(0, mp(c-1, v))));
					}
				}
				if(dist[v][0][c] > dist[u][r][c]+w){
					dist[v][0][c] = dist[u][r][c]+w;
					q.push(mp(-dist[v][0][c], mp(0, mp(c, v))));
				}
			}
			else{ // v é vila
				if(r >= w){ // continue jump
					if(dist[v][r-w][c] > dist[u][r][c]){
						dist[v][r-w][c] = dist[u][r][c];
						q.push(mp(-dist[v][r-w][c], mp(r-w, mp(c, v))));
					}
				}
				if(l >= w && c > 0){ // start jump
					if(dist[v][l-w][c-1] > dist[u][r][c]){
						dist[v][l-w][c-1] = dist[u][r][c];
						q.push(mp(-dist[v][l-w][c-1], mp(l-w, mp(c-1, v))));
					}
				}

				if(dist[v][0][c] > dist[u][r][c]+w){
					dist[v][0][c] = dist[u][r][c]+w;
					q.push(mp(-dist[v][0][c], mp(0, mp(c, v))));
				}
			}
		}
	}

	return ans;
}

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		scanf("%d %d %d %d %d", &a, &b, &m, &l, &k);
		g.assign(a+b+1, vector<pair<int, int> > ());

		for(int i = 0; i < m; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			g[u].push_back(mp(v, w));
			g[v].push_back(mp(u, w));
		}

		printf("%d\n", dijkstra());
	}

	return 0;
}