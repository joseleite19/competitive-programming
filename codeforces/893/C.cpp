#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ford(i, n) for(int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;

const int N = 100005;

vector<int> g[N];
int v[N], vis[N];

int dfs(int u){
	int ans = v[u];
	vis[u] = 1;
	for(int x : g[u]) if(!vis[x])
		ans = min(ans, dfs(x));
	return ans;
}

int main(){

	int n, m;

	scanf("%d %d", &n, &m);

	fore(i, 1, n+1) scanf("%d", v+i);

	int a, b;
	while(m--){
		scanf("%d %d", &a, &b);
		g[a].pb(b), g[b].pb(a);
	}

	ll ans = 0;

	fore(i, 1, n+1) if(!vis[i]){
		ans += dfs(i);
	}
	printf("%lld\n", ans);

    return 0;
}
