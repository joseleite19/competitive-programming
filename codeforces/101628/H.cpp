#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define ford(i, n) for(int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;

const int N = 100005;

vector<int> g[N];
int n, c, m, p[N], dp[N], mark[N], dpm[N], markm[N];

int f(int u){
	int &ans = dp[u];
	if(mark[u]) return ans;
	mark[u] = 1;
	if(u == n) return ans = p[u];
	
	ans = -1e9;
	for(int v : g[u]) ans = max(ans, f(v));
	ans += p[u];
	return ans;
}

int fm(int u){
	int &ans = dpm[u];
	if(markm[u]) return ans;
	markm[u] = 1;
	if(u == n) return ans = p[u];
	
	ans = 1e9;
	for(int v : g[u]) ans = min(ans, f(v));
	ans += p[u];
	return ans;
}

int main(){

	scanf("%d %d %d", &n, &c, &m);

	int x, a, b;

	forn(i, c) scanf("%d", &x), p[x] = 1;

	forn(i, m) scanf("%d %d", &a, &b), g[a].pb(b);

	printf("%d %d\n", fm(1), f(1));

    return 0;
}
