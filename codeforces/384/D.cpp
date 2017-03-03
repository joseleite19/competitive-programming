#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000000000000
using namespace std;

vector<int> g[200005];

int n, v[200005];

long long sum[200005], d[200005];

long long dfs(int u, int p){
	
	sum[u] = v[u];
	d[u] = -oo;
	long long ans1 = -oo, ans2 = -oo, ans = -oo;
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(v == p) continue;

		ans = max(ans, dfs(v, u));
		sum[u] += sum[v];
		d[u] = max(d[u], d[v]);
		if(d[v] > ans1) ans2 = ans1, ans1 = d[v];
		else if(d[v] > ans2) ans2 = d[v];
	}
	if(ans1 != -oo && ans2 != -oo) ans = max(ans, ans1+ans2);
	d[u] = max(d[u], sum[u]);

	return ans;
}

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	int u, v;

	for(int i = 0; i < n-1; i++){
		scanf("%d %d", &u, &v); u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	long long ans = dfs(0, 0);

	if(ans == -oo) printf("Impossible\n");
	else printf("%lld\n", ans);

	return 0;
}