#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo (1000000000000000000)

using namespace std;

long long dist[1003][102];
int mark[1003][102], pass;

vector<pair<int, long long> > g[1003];

long long p[1003];

int n, m;
long long dijkstra(int s, int e, int c){
	dist[s][0] = 0;
	mark[s][0] = pass;
	priority_queue< pair<long long, pair<int, int> > > q; // <sum, <tank, vx>>
	q.push(mp(0, mp(0, s)));

	while(!q.empty()){
		long long sum = -q.top().ff;
		int tank = q.top().ss.ff;
		int u = q.top().ss.ss; q.pop();
		if(u == e) return sum;

		for(size_t i = 0; i < g[u].size(); i++){
			int v = g[u][i].ff;
			int w = g[u][i].ss;
			for(int comprar = max(0, w - tank); comprar+tank <= c; comprar++){
				int cap = comprar+tank - w;
				long long ww = sum + comprar*p[u];
				if(mark[v][cap] != pass){
					mark[v][cap] = pass;
					dist[v][cap] = oo;
				}
				if(dist[v][cap] > ww){
					dist[v][cap] = ww;
					q.push(mp(-ww, mp(cap, v)));
				}
			}
		}
	}

	return oo;
}

int main(){
	

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		scanf("%lld", p+i);

	for(int i = 0; i < m; i++){
		int u, v; long long d;
		scanf("%d %d %lld", &u, &v, &d);

		g[u].push_back(mp(v, d));
		g[v].push_back(mp(u, d));
	}

	int q;

	scanf("%d", &q);

	while(q--){
		pass++;
		int s, e, c;
		scanf("%d %d %d", &c, &s, &e);
		long long ret = dijkstra(s, e, c);
		if(ret == oo) printf("IMPOSSIVEL\n");
		else printf("%lld\n", ret);
	}

	return 0;
}