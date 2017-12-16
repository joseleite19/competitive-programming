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
const int N = 2005;
const int E = 30006;

vector<int> g[N];

int ne;

struct Edge{
    int from, to;
    ll cap;
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
    edge[ne] = {u, v, c};
    g[u].pb(ne++);
}

char s[55][55];

int main(){

    int t;
    scanf("%d", &t);

    int n, m;
    while(t--){
        scanf("%d %d", &n, &m);
        ne = 0;

        forn(i, n) scanf(" %s", s[i]);

        source = N-1, target = N-2;
        int cnt = 0, u, v;
        forn(i, n) forn(j, m){
            if(s[i][j] != '*') continue;
            if((i+j)&1)
                addEdge(i*m+j, target, 1), addEdge(target, i*m+j, 0);
            else
                addEdge(source, i*m+j, 1), addEdge(i*m+j, source, 0);
            
            cnt++;
            if(s[i+1][j] == '*'){
                u = i*m + j, v = (i+1)*m + j;
                if((i + j) & 1) swap(u, v);
                addEdge(u, v, 1);
                addEdge(v, u, 0);
            }
            if(s[i][j+1] == '*'){
                u = i*m + j, v = i*m + j+1;
                if((i + j) & 1) swap(u, v);
                addEdge(u, v, 1);
                addEdge(v, u, 0);
            }
        }


        ll ans = flow();
        ans += cnt - 2*ans;

        printf("%lld\n", ans);

        forn(i, N) g[i].clear();
    }

}


