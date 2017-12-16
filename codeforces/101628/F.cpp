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

int n, m, t, k, p;

vector<pair<int, int> > g[N];
int sp[N];

ll d[N];

ll f(){

	fore(i, 1, n+1) d[i] = 1e18;
	d[1] = 0;
	priority_queue<pair<ll, int> > q;
	q.emplace(0, 1);

	int u;
	ll dd, tmp;
	while(!q.empty()){
		tie(dd, u) = q.top(); q.pop(); dd = -dd;
		if(dd > d[u]) continue;
		for(auto v : g[u]){
			tmp = d[u] + v.ss + sp[v.ff];
			if(tmp < d[ v.ff ]){
				d[ v.ff ] = tmp;
				q.emplace(-tmp, v.ff);
			}
		}
	}
	return d[n];
}

int main(){

	scanf("%d %d %d %d %d", &n, &m, &t, &k, &p);

	forn(i, p){
		int x;
		scanf("%d", &x);
		sp[x] = k;
	}

	forn(i, m){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a].eb(b,c*60);
		//g[b].eb(a,c*60);
	}

	ll ans = f();
	if(ans > 60LL * t) ans = -1;
	printf("%lld\n", ans);



    return 0;
}
