#include <bits/stdc++.h>

#define oo 1000000000
#define ff first
#define ss second
#define mp make_pair

using namespace std;
int p[200005], w[200005], c[200005], parent[200005], L[200005];
int dp[200005][20], dp2[200005][20], vis[200005], pw[200005];
vector<pair<int, int> > g[200005];
int n;

int lg(int x){
	int ans = 0;
	while((1 << (ans+1)) <= x) ans++;
	return ans;
}

int dfs(int u){
	vis[u] = 1;
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i].ff;
		int x = g[u][i].ss;
		if(!vis[v]){
			parent[v] = u;
			L[v] = L[u]+1;
			pw[v] = x;

			dfs(v);
		}
	}
}

int f(int v, int j){
	if(j == 0) return parent[v];
	if(dp[v][j] != -1) return dp[v][j];

	return dp[v][j] = f(f(v, j-1), j-1);
}

int h(int v, int j){
	if(j == 0) return pw[v];
	if(dp2[v][j] != -1) return dp2[v][j];

	return dp2[v][j] = max(h(v, j-1), h(f(v, j-1), j-1));
}


int lca(int u, int v){
	if(L[u] < L[v]) swap(u, v); //u é o mais longe

	int ans = 0;

	for(int k = lg(L[u]); k >= 0; k--){
		if(L[ f(u, k) ] >= L[v]){
			ans = max(ans, h(u, k));
			u = f(u, k);
		}
	}

	if(u == v) return ans;

	for(int k = lg(L[u]); k >= 0; k--){
		if(f(u, k) != f(v, k)){
			ans = max(ans, h(u, k));
			ans = max(ans, h(v, k));
			u = f(u, k);
			v = f(v, k);
		}
	}

	ans = max(ans, pw[u]);
	ans = max(ans, pw[v]);

	return ans;
}

int make(int x){
	p[x] = x;
}

int acha(int x){
	return (x == p[x] ? x : p[x] = acha(p[x]));
}

void join(int x, int y){
	p[acha(x)] = acha(y);
}

int main(){
	int n, m;

	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
		scanf("%d", w+i);

	for(int i = 0; i < m; i++)
		scanf("%d", c+i);

	vector< pair<int, pair<int, pair<int, int> > > > edges;

	int a[200005], b[200005];

	for(int i = 0; i < m; i++){
		scanf("%d %d", a+i, b+i);
		a[i]--; b[i]--;

	}
	long long s;
	scanf("%lld", &s);
	for(int i = 0; i < m; i++){
		edges.push_back(mp(w[i], mp(i, mp(a[i], b[i]))));
	}

	sort(edges.begin(), edges.end());

	for(int i = 0; i < n; i++)
		make(i);

	long long tot = 0;

	for(int i = 0; i < (int)edges.size(); i++){
		int x = edges[i].ss.ss.ff;
		int y = edges[i].ss.ss.ss;
		if(acha(x) != acha(y)){
			join(x, y);
			tot += edges[i].ff;

			g[x].push_back(mp(y, edges[i].ff));
			g[y].push_back(mp(x, edges[i].ff));
		}
	}

	L[0] = 1;
	pw[0] = -oo;
	vis[0] = 1;
	dfs(0);
	memset(dp, -1, sizeof dp);
	memset(dp2, -1, sizeof dp2);

	long long ans = tot;
	int id = -1;

	for(int i = 0; i < (int)edges.size(); i++){
		int x = edges[i].ss.ss.ff;
		int y = edges[i].ss.ss.ss;
		int tmp = lca(x, y);
		int k = edges[i].ss.ff;
	
		long long aux = tot - tmp + w[k] - s/c[k];
		if(aux < ans){
			ans = aux;
			id = i;
		}
	}

	for(int i = 0; i < n; i++)
		make(i);

	vector<int> vans;
	if(id != -1){
		int x = edges[id].ss.ss.ff;
		int y = edges[id].ss.ss.ss;
		join(x, y);
		int k = edges[id].ss.ff;
		w[k] -= s/c[k];
		vans.push_back(k);
	}

	for(int i = 0; i < (int)edges.size(); i++){
		int x = edges[i].ss.ss.ff;
		int y = edges[i].ss.ss.ss;
		if(acha(x) != acha(y)){
			join(x, y);
			vans.push_back(edges[i].ss.ff);
		}
	}
	

	printf("%lld\n", ans);

	for(int i = 0; i < (int)vans.size(); i++){
		printf("%d %d\n", vans[i]+1, w[ vans[i] ]);
	}
}