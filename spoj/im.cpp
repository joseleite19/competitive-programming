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
const int N = 200005;
const int E = 3000006;

vector<int> g[N];

int ne;

struct Edge{
    int from, to;
    ll cap;
    inline void set(int f, int t, ll c){ from = f, to = t, cap = c; }
} edge[E];

int lvl[N], vis[N], pass, source, target, p[N], px[N];

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
    edge[ne].set(u, v, c);
    g[u].pb(ne++);
}

inline int in(int u){ return 2*u; }
inline int out(int u){ return 2*u+1; }

int main(){
    int t;

    scanf("%d", &t);

    int n, m;
    while(t--){
        scanf("%d %d", &n, &m);
        ne = 0;

        int a, b;
        forn(i, m){
            scanf("%d %d", &a, &b);
            if(0 < a && a <= n && 0 < b && b <= n){
                addEdge(out(a), in(b), 1);
                addEdge(out(b), in(a), 1);
            }
        }
        fore(i, 1, n) addEdge(in(i), out(i), 1), addEdge(out(i), in(i), 0);

        source = out(2), target = 0;

        addEdge(out(1), target, 1);
        addEdge(target, out(1), 0);
        addEdge(out(3), target, 1);
        addEdge(target, out(3), 0);

        printf("%s\n", flow() == 2? "YES" : "NO");
        forn(i, N) g[i].clear();
    }

}


