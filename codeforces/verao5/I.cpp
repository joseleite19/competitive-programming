#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

int n;
long long t;

pair<long long, long long> v[100005];
char dir[100005];

long long dist[100005];

int vis[100005];

map<long long, set<pair<long long, int> > > linha;
map<long long, set<pair<long long, int> > > coluna;

vector<pair<int, long long> > g[100005];

void solve(){

	for(int i = 0; i < n; i++)
		dist[i] = 1LL << 62;

	priority_queue<pair<long long, int> > pq; // tempo, id

	pq.push(mp(0LL, 0));
	dist[0] = 0;

	while(!pq.empty()){
		long long d = -pq.top().ff;
		int u = pq.top().ss;
		pq.pop();
		
		if(d > dist[u]) continue;

		for(int i = 0; i < (int)g[u].size(); i++){
			int v = g[u][i].ff;
			long long w = g[u][i].ss;
			if(dist[v] > d+w){
				dist[v] = d+w;
				pq.push(mp(-dist[v], v));
			}
		}
	}
}



int main(){

	scanf("%d %lld", &n, &t);

	for(int i = 0; i < n; i++){
		scanf("%lld %lld %c", &v[i].ff, &v[i].ss, dir+i);
		linha[ v[i].ff ].insert(mp(v[i].ss, i));
		coluna[ v[i].ss ].insert(mp(v[i].ff, i));
	}

	// for(int i = 0; i < n; i++){
	// 	if(dir[i] == 'U'){
	// 		 // = linha[ v[i].ff ];
	// 		set<pair<long long, int> >::iterator it = linha[ v[i].ff ].upper_bound(mp(v[i].ss, i));
	// 		if(it == linha[ v[i].ff ].end()) continue;
	// 		g[i].push_back(mp(it->ss, it->ff - v[i].ss));
	// 	}
	// 	if(dir[i] == 'D'){
	// 		set<pair<long long, int> >::iterator it = linha[ v[i].ff ].lower_bound(mp(v[i].ss, i));
	// 		if(it == linha[ v[i].ff ].begin()) continue;
	// 		it--;
	// 		g[i].push_back(mp(it->ss, v[i].ss - it->ff));
	// 	}
	// 	if(dir[i] == 'R'){
	// 		set<pair<long long, int> >::iterator it = coluna[ v[i].ss ].upper_bound(mp(v[i].ff, i));
	// 		if(it == coluna[ v[i].ss ].end()) continue;
	// 		g[i].push_back(mp(it->ss, it->ff - v[i].ss));
	// 	}
	// 	if(dir[i] == 'L'){
	// 		set<pair<long long, int> >::iterator it = coluna[ v[i].ss ].lower_bound(mp(v[i].ff, i));
	// 		if(it == coluna[ v[i].ss ].begin()) continue;
	// 		it--;
	// 		g[i].push_back(mp(it->ss, v[i].ss - it->ff));
	// 	}
	// }

	for(int i = 0; i < n; i++){
		printf("%d: ", i);
		for(int j = 0; j < (int)g[i].size(); j++)
			printf(" %d", g[i][j].ff);
		printf("\n");
	}

	solve();

	for(int i = 0; i < n; i++){
		printf("..%d %lld\n", i, dist[i]);
		if(dist[i] == 1LL << 62) continue;
		long long delta = t - dist[i];
		if(dir[i] == 'U') v[i].ff += delta;
		if(dir[i] == 'D') v[i].ff -= delta;
		if(dir[i] == 'R') v[i].ss += delta;
		if(dir[i] == 'L') v[i].ss -= delta;
	}

	for(int i = 0; i < n; i++)
		printf("%lld %lld\n", v[i].ff, v[i].ss);


	return 0;
}