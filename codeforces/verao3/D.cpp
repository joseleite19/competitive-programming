#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000000000000

using namespace std;

vector<pair<int, int> > g[100005];

int pp[100005];
int color[100005];
int mark[100005];
long long dist[100005];

int n, k, l;
long long dijkstra(){
	for(int i = 1; i <= k; i++)
		dist[i] = oo;

	priority_queue<pair<long long, int> > pq;
	for(int i = 0; i < n; i++){
		color[ pp[i] ] = pp[i];
		dist[ pp[i] ] = 0;
		pq.push(mp(0LL, pp[i]));
	}

	long long ans = oo;
	while(!pq.empty()){
		long long d = -pq.top().ff;
		int u = pq.top().ss; pq.pop();

		if(d > dist[u]) continue;

		for(int i = 0; i < (int)g[u].size(); i++){
			int v = g[u][i].ff;
			int w = g[u][i].ss;
			if(color[v] && color[v] != color[u]){
				ans = min(ans, d + dist[v] + w);
			}
			if(d + w < dist[v]){
				dist[v] = d + w;
				color[v] = color[u];
				pq.push(mp(-dist[v], v));
			}
		}
	}
	return ans;
}

int main(){

	scanf("%d %d %d", &n, &k, &l);

	for(int i = 0; i < n; i++){
		scanf("%d", pp+i);
		if(mark[ pp[i] ]){
			printf("0\n");
			return 0;
		}
		mark[ pp[i] ] = 1;
	}

	for(int i = 0; i < l; i++){
		int u, v, d;

		scanf("%d %d %d", &u, &v, &d);

		g[u].push_back(mp(v, d));
		g[v].push_back(mp(u, d));
	}

	long long ans = 3*dijkstra();

	printf("%lld\n", ans);

	return 0;
}