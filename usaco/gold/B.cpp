#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define MOD 1000000007
#define ford(i, n) for(int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;

const int N = 1000005;

void file(){
	freopen("barnpainting.in", "r", stdin);
	freopen("barnpainting.out", "w", stdout);
}

ll dp[N][4];
int c[N];

vector<int> g[N];

ll add(ll a, ll b){
	return a + b >= MOD ? a + b - MOD : a + b;
}

ll mul(ll a, ll b){
	return (a * b) % MOD;
}

ll f(int u, int l, int p){
	if(c[u] && c[u] == l) return 0;
	ll &ret = dp[u][l];
	if(~ret) return ret;
	ret = 0;
	if(c[u]){
		ll tmp = 1;
		for(int v : g[u]) if(v != p){
			tmp = mul(tmp, f(v, c[u], u));
		}
		ret = add(ret, tmp);
	}
	else{
		fore(x, 1, 4) if(x != l){
			ll tmp = 1;
			for(int v : g[u]) if(v != p){
				tmp = mul(tmp, f(v, x, u));
			}
			ret = add(ret, tmp);
		}
	}

	return ret;
}

int main(){
	file();

	memset(dp, -1, sizeof dp);
	int n, k;
	scanf("%d %d", &n, &k);

	fore(i, 1, n){
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].pb(b), g[b].pb(a);
	}

	forn(i, k){
		int b, cc;
		scanf("%d %d", &b, &cc);
		c[b] = cc;
	}

	printf("%lld\n", f(1, 0, -1));





    return 0;
}
