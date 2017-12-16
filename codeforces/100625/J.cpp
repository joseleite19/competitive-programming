#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int h, w, fora = 200*200-1;

char mat[200][200];

long long d[200*200];
long long d2[200*200];

int color[200*200];

int vis[200*200];

int tov(int i, int j){
	return i*200 + j;
}

vector< vector<pair<int, long long> > > G;

void dijkstra(){

	for(int i = 0; i < 200*200; i++) d[i] = 1000000000000000000;

	priority_queue<pair<long long, int> > q;
	d[fora] = 0;
	q.push(mp(0, fora));

	while(!q.empty()){
		int u = q.top().ss;
		// printf("..%d %lld\n", u, d[154]);
		long long p = -q.top().ff; q.pop();

		for(int i = 0; i < int(G[u].size()); i++){
			int v = G[u][i].ff;
			long long e = G[u][i].ss;
			// printf("%d %d %lld %lld %lld\n", u, v, e, d[u], d[v]);

			if(d[u] + e < d[v]){
				d[v] = d[u] + e;
				q.push(mp(-d[v], v));
			}
		}
	}
}
vector<int> povo;

long long dijkstra2(){
	long long ans = 1000000000000000000;

	for(int i = 0; i < 200*200; i++) d2[i] = 1000000000000000000;

	priority_queue<pair<long long, int> > q;
	d2[ povo[0] ] = 0;
	q.push(mp(0, povo[0]));
	color[ povo[0] ] = 1;

	d2[ povo[1] ] = 0;
	q.push(mp(0, povo[1]));
	color[ povo[1] ] = 2;

	// printf("%d %d\n", povo[0], povo[1]);

	while(!q.empty()){
		int u = q.top().ss;
		long long p = -q.top().ff; q.pop();
		// printf("%d %d\n", u, color[u]);

		for(int i = 0; i < int(G[u].size()); i++){
			int v = G[u][i].ff;
			long long e = G[u][i].ss;
			// printf("%d %d\n", color[v], color[v]);

			if(color[v] && (color[u] | color[v]) == 3){
				// printf("asd %d->%d %lld %lld %lld %d\n", u, v, d2[u], d2[v], d[v], vis[v]);
				ans = min(ans, d2[u] + d2[v] + d[v] - vis[v]);
			}

			if(d2[u] + e < d2[v]){
				d2[v] = d2[u] + e;
				color[v] |= color[u];
				q.push(mp(-d2[v], v));
			}
			else if(d2[u] + e == d2[v]) color[v] |= color[u];
		}
	}

	assert(ans != 1000000000000000000);
	return ans;
}

int main(){
	int tc;

	scanf("%d", &tc);

	int dx[] = {0, 0,-1, 1};
	int dy[] = {1,-1, 0, 0};

	while(tc--){
		povo.clear();

		scanf("%d %d", &h, &w);

		G.assign(200*200, vector<pair<int, long long> >());
		memset(vis, 0, sizeof vis);

		for(int i = 0; i < h; i++)
			scanf(" %s", mat[i]);

		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(mat[i][j] == '*') continue;
				if(mat[i][j] == '$') povo.push_back(tov(i, j));
				if(mat[i][j] == '#') vis[ tov(i, j) ] = 1;
				for(int q = 0; q < 4; q++){
					int x = i+dx[q], y = j + dy[q];
					if(x < 0 || y < 0 || x >= h || y >= w || mat[x][y] == '*') continue;
					G[tov(i, j)].push_back(mp(tov(x, y), mat[x][y] == '#'));
					G[tov(x, y)].push_back(mp(tov(i, j), mat[i][j] == '#'));
				}
			}
		}

		for(int i = 0; i < h; i++){
			if(mat[i][0] != '*'){
				G[tov(i, 0)].push_back(mp(fora, 0));
				G[fora].push_back(mp(tov(i, 0), mat[i][0] == '#'));
			}
			if(mat[i][w-1] != '*'){
				G[tov(i,w-1)].push_back(mp(fora, 0));
				G[fora].push_back(mp(tov(i,w-1), mat[i][w-1] == '#'));
			}
		}

		for(int j = 0; j < w; j++){
			if(mat[0][j] != '*'){
				G[tov(0, j)].push_back(mp(fora, 0));
				G[fora].push_back(mp(tov(0, j), mat[0][j] == '#'));
			}
			if(mat[h-1][j] != '*'){
				G[tov(h-1, j)].push_back(mp(fora, 0));
				G[fora].push_back(mp(tov(h-1, j), mat[h-1][j] == '#'));
			}
		}

		memset(color, 0, sizeof color);

		dijkstra();

		// printf("%lld %lld\n", d[ povo[0] ], d[ povo[1] ]);

		printf("%lld\n", dijkstra2());
	}

	return 0;
}