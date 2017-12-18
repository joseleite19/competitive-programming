#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;

const ll oo = 1e18;

const int N = 1000, E = 250000;
vector<int> g[N];

int ne;
struct Edge{
    int from, to;
    ll cap;
} edge[E];

int lvl[N], vis[N], pass, source, target, px[N];

ll run(int s, ll minE){
    if(s == target) return minE;

    ll ans = 0;

    for(; px[s] < (int)g[s].size(); px[s]++){
        int e = g[s][ px[s] ];
        auto &v = edge[e], &rev = edge[e^1];
        if(lvl[v.to] != lvl[s]+1 || !v.cap) continue;
        ll tmp = run(v.to, min(minE, v.cap));
        v.cap -= tmp, rev.cap += tmp;
        ans += tmp, minE -= tmp;
        if(minE == 0) break;
    }
    return ans;
}

int bfs(){

    queue<int> q;
    q.push(source);
    lvl[source] = 1;
    vis[source] = ++pass;

    while(!q.empty()){
        int u = q.front(); q.pop();
        px[u] = 0;

        for(int e : g[u]){
            auto v = edge[e];
            if(v.cap <= 0 || vis[v.to] == pass) continue;
            vis[v.to] = pass;
            lvl[v.to] = lvl[u]+1;
            q.push(v.to);
        }
    }
    return vis[target] == pass;
}

ll flow(){
    ll ans = 0;
    while(bfs()) ans += run(source, oo);
    return ans;
}

void addEdge(int u, int v, ll c){
    edge[ne] = {u, v, c};
    g[u].pb(ne++);
    edge[ne] = {v, u, 0};
    g[v].pb(ne++);
}

int e, c, k;
ll x[N], y[N], cx[N], cy[N];

inline ll cost(int i, int j){
	ll dx = x[i] - cx[j], dy = y[i] - cy[j];
	return dx * dx + dy * dy;
}

ll doit(ll mid){
	source = N-1, target = N-2;

	forn(i, e){
		addEdge(source, i, 1);
		forn(j, c) if(cost(i, j) <= mid){
			addEdge(i, e+j, 1);
		}
	}
	forn(j, c) addEdge(e+j, target, 1);
	ll ret = flow();
	ne = 0;
	forn(i, N) g[i].clear();
	return ret;
}

int main(){
	
	scanf("%d %d %d", &e, &c, &k);

	forn(i, e) scanf("%lld %lld", x+i, y+i);

	forn(i, c) scanf("%lld %lld", cx+i, cy+i);

	ll L = 0, R = oo;

	while(L+1 < R){
		ll mid = (L+R)/2;
		ll t = doit(mid);
		if(t >= k) R = mid;
		else L = mid+1;
	}
	if(doit(L) < k) L = R;

	printf("%lld\n", L);

}
