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

const int N = 1000006;

vector<pair<int, int> > g[N], gt[N], h[N];

vector<int> S;

int vis[N], cor[N];

ll v[N];

void dfs(int u){
	vis[u] = 1;
	for(auto x : g[u]) if(!vis[x.ff])
		dfs(x.ff);
	S.pb(u);
}

int e;
void dfst(int u){
	cor[u] = e;
	for(auto x : gt[u]) if(!cor[x.ff])
		dfst(x.ff);
}

ll calc(ll x){
	return (x * (x + 1) * (2 * x - 1) / 6 + x * (x + 1) / 2) / 2;
}

ll val(ll x){
	//(x - 0) + (x - 1) + (x - 2) + (x - 3) + (x - 4) + ...
	//(n+1)*x - n*(n+1)/2
	//(4 - 0) + (4 - 1) + (4 - 2)
	//4 + 3 + 2
	ll lo = 0, hi = x;
	while(lo+1 < hi){
		ll mid = (lo + hi) / 2;
		if(x < calc(mid)) hi = mid-1;
		else lo = mid;
	}

	if(x < calc(hi)) hi = lo;

	printf(".%lld %lld\n", hi, calc(hi));
	return (hi+1)*x - calc(hi);
}

ll dp[N];

ll f(int u){
	ll &ans = dp[u];
	if(~ans) return ans;
	ans = 0;
	for(auto x : h[u])
		ans = max(ans, x.ss + f(x.ff));
	return ans += v[u];
}

int main(){
	memset(dp, -1, sizeof dp);
	int n, m;

	scanf("%d %d", &n, &m);

	while(m--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a].eb(b, c);
		gt[b].eb(a, c);
	}
	fore(i, 1, n+1) if(!vis[i])
		dfs(i);

	reverse(S.begin(), S.end());
	for(int x : S) if(!cor[x])
		e++, dfst(x);

	fore(i, 1, n+1){
		for(auto x : g[i]){
			if(cor[i] == cor[x.ff]) v[ cor[i] ] += val(x.ss), printf("%d %lld\n", x.ss, val(x.ss));
			else h[ cor[i] ].eb(cor[x.ff], x.ss);
		}
	}

	int s;

	scanf("%d", &s);

	printf("%lld\n", f(cor[s]));

    return 0;
}
