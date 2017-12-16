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

const int N = 2000006;

int n, m, L[N];
vector<ll> v[N];
vector<ll> s[N];

void precomp(int p){
	if(p > n) return;
	if(2*p <= n){
		precomp(2*p);
		for(int x : v[2*p]) v[p].pb(x+L[2*p]);
	}
	if(2*p+1 <= n){
		precomp(2*p+1);
		for(int x : v[2*p+1]) v[p].pb(x+L[2*p+1]);
	}
	v[p].pb(0);
	sort(v[p].begin(), v[p].end());
	s[p].resize(v[p].size());
	partial_sum(v[p].begin(), v[p].end(), s[p].begin());
}

int vis[N], pass = 1;

ll f(int a, int h){
	if(a > n || !a) return 0;
	if(vis[a] == pass) return 0;
	vis[a] = pass;
	if(h <= 0) return 0;
	int x = 1, y = 1;
	if(2*a <= n) x = vis[2*a] != pass;
	if(2*a+1 <= n) y = vis[2*a+1] != pass;
	ll ans = h;
	if(x && y){
		int id = upper_bound(v[a].begin(), v[a].end(), h) - v[a].begin();
		id--;
		if(id >= 0) ans = 1LL * h * (id+1) - s[a][id];
	}
	else ans += f(2*a, h - L[2*a]) + f(2*a+1, h - L[2*a+1]);
	ans += f(a / 2, h - L[a]);
	//printf("%d %d %lld\n", a, h, ans);
	return ans;
}

int main(){

	scanf("%d %d", &n, &m);

	fore(i, 2, n+1) scanf("%d", L+i);
	precomp(1);

	int a, h;
	while(m--){
		scanf("%d %d", &a, &h);	
		pass++;
		printf("%lld\n", f(a, h));
	}

	return 0;
}
