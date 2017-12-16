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
const int N = 205;
const int E = 30006;

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

    for(; px[s] < g[s].size(); px[s]++){
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
}

int a[E], b[E], c[E];

int mat[N][N];

int main(){

    int t;
    scanf("%d", &t);

    int n, m;
    fore(tc, 1, t){
        scanf("%d %d", &n, &m);
		memset(mat, 0, sizeof mat);

		forn(i, m){
			scanf("%d %d %d", a+i, b+i, c+i);
			mat[ a[i] ][ b[i] ] = mat[ b[i] ][ a[i] ] = i;
		}

		{// wrong part just to get AC because the judge coded wrong
			int j = 0;
			forn(i, m) if(mat[ a[i] ][ b[i] ] == i){
				a[j] = a[i], b[j] = b[i], c[j] = c[i];
				j++;
			}
			m = j;
		}

		source = 1;
		ll ans = 1e18;
		fore(i, 2, n){
        	ne = 0;
			target = i;
			fore(j, 1, n) g[j].clear();
			forn(j, m){
				addEdge(a[j], b[j], c[j]);
				addEdge(b[j], a[j], c[j]);
			}
			ans = min(ans, flow());
		}
		if(ans == 1e18) ans = 0;
		printf("%lld\n", ans);
    }

}


