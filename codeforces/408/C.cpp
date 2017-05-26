#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int in[300005], n;

vector<int> g[300005];

long long power[300005];

int vis[300005];

long long delta[300005];

long long solve(int s){
	long long ans = power[s];

	vis[s] = 1;
	for(int i = 0; i < (int)g[s].size(); i++){
		int v = g[s][i];
		if(vis[v]) continue;
		vis[v] = 1;
		power[v]++;
	}

	for(int v = 1; v <= n; v++){
		if(vis[v]) continue;
		vis[v] = 1;
		power[v] += 2;
	}
	for(int v = 1; v <= n; v++)
		ans = max(ans, power[v]);



	// priority_queue<pair<long long, int> > q;
	// q.push(mp(power[s], s));

	// while(!q.empty()){
	// 	long long d = q.top().ff;
	// 	ans = max(ans, d);
	// 	int u = q.top().ss; q.pop();
	// 	vis[u] = 1;

	// 	for(int i = 0; i < (int)g[u].size(); i++){
	// 		int v = g[u][i];
	// 		if(vis[v]) continue;
	// 		delta[v]++;
	// 		power[v] += delta[u]+1;
	// 		q.push(mp(power[v], v));
	// 	}
	// }
	return ans;
}

int main(){

	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		scanf("%lld", power+i);

	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
		in[u]++, in[v]++;
	}

	int id = 1;
	for(int i = 1; i <= n; i++)
		if(power[id] < power[i])
			id = i;

	multiset<long long> p;

	for(int i = 1; i <= n; i++) p.insert(power[i]);

	long long ans = 1000000000000000000;

	for(int u = 1; u <= n; u++){
		long long tmp = power[u];
		p.erase(p.find(power[u]));
		for(int v : g[u]){
			tmp = max(tmp, power[v]+1);
			p.erase(p.find(power[v]));
		}
		if(p.size()) tmp = max(tmp, 2 + *p.rbegin());
		ans = min(ans, tmp);

		p.insert(power[u]);
		for(int v : g[u]){
			p.insert(power[v]);
		}
	}

	printf("%lld\n", ans);

	return 0;
}