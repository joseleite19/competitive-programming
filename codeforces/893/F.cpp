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
const int B = 320;

int n, root, a[N], t = -1, L[N], R[N], d[N], v[N], vis[N];
int h[B][N];

vector<int> g[N];

void dfs(int u, int p){
	v[++t] = u;
	L[u] = t;
	for(int v : g[u]) if(v != p)
		d[v] = d[u]+1, dfs(v, u);
	R[u] = t;
}

int f(int x, int k){
	k = min(n, k + d[x]);
	int ans = 2000000000;
	int l = L[x] / B, r = R[x] / B, ll = L[x] % B, rr = R[x] % B;
	if(l != r){
		fore(e, l+1, r) ans = min(ans, h[e][k]);
		fore(e, ll, B) if(d[ v[B*l + e] ] <= k)
			ans = min(ans, a[ v[B*l + e] ]);
		fore(e, 0, rr+1) if(d[ v[B*r + e] ] <= k)
			ans = min(ans, a[ v[B*r + e] ]);
	}
	else fore(e, ll, rr+1) if(d[ v[B*l + e] ] <= k)
		ans = min(ans, a[ v[B*l + e] ]);
	return ans;
}


int main(){

	scanf("%d %d", &n, &root);

	fore(i, 1, n+1) scanf("%d", a+i);

	fore(i, 1, n){
		int q, w;
		scanf("%d %d", &q, &w);
		g[q].pb(w), g[w].pb(q);
	}

	dfs(root, root);
	
	fore(b, 0, B){
		fore(w, 0, B){
			if(B*b + w >= n) break;
			int &t = h[b][ d[ v[B*b+w] ] ];
			if(!t) t = a[ v[B*b + w] ];
			else t = min(a[ v[B*b + w] ], t);
		}
		if(!h[b][0]) h[b][0] = 2000000000;
		fore(w, 1, n+1){
			if(!h[b][w]) h[b][w] = h[b][w-1];
			else h[b][w] = min(h[b][w-1], h[b][w]);
		}
	}

	int last = 0;

	int m;

	scanf("%d", &m);

	int x, k;
	while(m--){
		scanf("%d %d", &x, &k);
		x = ((x + last) % n) + 1, k = (k + last) % n;
		last = f(x, k);
		printf("%d\n", last);
	}


    return 0;
}
