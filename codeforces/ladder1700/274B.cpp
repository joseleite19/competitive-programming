#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

vector<int> g[100005];
long long ans, v[100005];

pair<long long, long long> dfs(int u, int p){

	pair<long long, long long> tmp = mp(0, 0);
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(v == p) continue;
		pair<long long, long long> tmp2 = dfs(v, u);
		
		tmp.ff = max(tmp.ff, tmp2.ff);
		tmp.ss = min(tmp.ss, tmp2.ss);
	}

	long long delta = tmp.ff + tmp.ss + v[u];
	delta *= -1;
	if(delta >= 0) tmp.ff += delta;
	else tmp.ss += delta;

	// printf("%d %lld %lld %lld\n", u+1, delta, tmp.ff, tmp.ss);
	return tmp;
}

int main(){

	int n;

	scanf("%d", &n);

	for(int i = 0; i < n-1; i++){
		int u, v;
		scanf("%d %d", &u, &v); u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for(int i = 0; i < n; i++)
		scanf("%lld", v+i);

	pair<long long, long long> tmp = dfs(0, 0);
	ans = abs(tmp.ff) + abs(tmp.ss);

	printf("%lld\n", ans);


	return 0;
}