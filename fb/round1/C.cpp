#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000000000000

using namespace std;

int n, m, k;

vector<vector<pair<int, int> > > g;
int s[5003], d[5003];

long long dist[102][5003][3];

long long solve(){
	// 0 - cheguei no vertice sem ngm, mas o i foi o ultimo entregue
	// 1 - cheguei no vertice com o i
	// 2 - cheguei no vertice com i e i+1
	priority_queue< pair<long long, pair<int, pair<int, int> > > > pq; // dist, vx, last, state
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= k; j++)
			for(int ii = 0; ii < 3; ii++)
				dist[i][j][ii] = oo;

	dist[0][0][0] = 0;

	pq.push(mp(0, mp(0, mp(0, 0))));

	int cnt = 0;
	while(!pq.empty()){
		long long dd = -pq.top().ff;
		int u = pq.top().ss.ff;
		int last = pq.top().ss.ss.ff;
		int state = pq.top().ss.ss.ss; pq.pop();

		if(dd > dist[u][last][state]) continue;

		if(u == d[k] && last == k && state == 0) break;

		if(u == d[last]){
			if(state == 1 && dist[u][last][0] > dd){
				dist[u][last][0] = dd;
				pq.push(mp(-dd, mp(u, mp(last, 0))));
			}
			if(state == 2 && dist[u][last+1][1] > dd){
				dist[u][last+1][1] = dd;
				pq.push(mp(-dd, mp(u, mp(last+1, 1))));
			}
		}

		if(last < k && u == s[last+1]){
			if(state == 0 && dist[u][last+1][1] > dd){
				dist[u][last+1][1] = dd;
				pq.push(mp(-dd, mp(u, mp(last+1, 1))));
			}
			if(state == 1 && dist[u][last][2] > dd){
				dist[u][last][2] = dd;
				pq.push(mp(-dd, mp(u, mp(last, 2))));
			}
		}

		for(int i = 0; i < (int)g[u].size(); i++){
			int v = g[u][i].ff, w = g[u][i].ss;

			long long ww = dd + w;
			if(dist[v][last][state] > ww){
				dist[v][last][state] = ww;
				pq.push(mp(-ww, mp(v, mp(last, state))));
			}
		}
	}

	long long ret = dist[ d[k] ][k][0];
	if(ret == oo) return -1;
	return ret;
}

int main(){
	int t;

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		scanf("%d %d %d", &n, &m, &k);

		g.assign(n, vector<pair<int, int> >());

		int u, v, w;
		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &u, &v, &w); u--; v--;
			g[u].push_back(mp(v, w));
			g[v].push_back(mp(u, w));
		}

		for(int i = 1; i <= k; i++){
			scanf("%d %d", s+i, d+i); s[i]--, d[i]--;
		}

		printf("Case #%d: %lld\n", tc, solve());
	}

	return 0;
}