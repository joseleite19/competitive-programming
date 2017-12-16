#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000

using namespace std;

vector< vector<pair<int, pair<long long, int> > > > g; // <vx, <edge weight, id reverse edge>>

vector<int> lvl, vis;
vector<size_t> px;
int source, target;


long long run(int s, long long minE){
	if(s == target) return minE;

	long long ans = 0;

	for(; px[s] < g[s].size(); px[s]++){
		auto &v = g[s][ px[s] ];
		if(lvl[v.ff] != lvl[s]+1 || !v.ss.ff) continue;
		long long tmp = run(v.ff, min(minE, v.ss.ff));
		v.ss.ff -= tmp;
		g[v.ff][v.ss.ss].ss.ff += tmp;
		ans += tmp;
		minE -= tmp;
		if(minE == 0) break;
	}
	return ans;
}

int pass;
int bfs(){

	queue<int> q;
	q.push(source);
	lvl[source] = 1;
	vis[source] = ++pass;

	while(!q.empty()){
		int u = q.front(); q.pop();
		px[u] = 0;

		for(auto v : g[u]){
			if(v.ss.ff <= 0 || vis[v.ff] == pass) continue;
			vis[v.ff] = pass;
			lvl[v.ff] = lvl[u]+1;
			q.push(v.ff);
		}
	}

	return vis[target] == pass;
}

long long flow(){

	long long ans = 0;
	while(bfs())
		ans += run(source, oo);
	return ans;
}

void addEdge(int u, int v, long long c){
	pair<int, pair<long long, int> > a, b;
	a = {u, {0, g[u].size()}};
	b = {v, {c, g[v].size()}};
	g[u].push_back(b);
	g[v].push_back(a);
}



int main(){
	int t;

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		


		printf("%lld\n", flow());
	}
	


	return 0;
}