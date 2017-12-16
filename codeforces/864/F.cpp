#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000007LL
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int Q = 400005;
const int N = 3003;

int n, m, q, p[N], L[N];
vector<int> g[N];
int ans[Q];
vector<tuple<int, int, int> > w[N];

int mat[N][N];
int r[N][N];

void dfs2(int u, int s){
    r[s][u] = 1;
    for(int v : g[u]) if(!r[s][v])
        dfs2(v, s);
}

int vis[N], pass;

bool check_slow(int s, int u, int v){
    vis[v] = pass;
    if(v == u) return 1;
    for(int w : g[v]) if(vis[w] != pass && w != s){
        if(check_slow(s, u, w))
            return 1;
    }
    return 0;
}

bool dfs(int u, int s){
    for(int v : g[u]){ 
        if(p[v] != -1){
            pass++; if(check_slow(s, u, v)) return false;
            continue;
        }
        p[v] = u;
        L[v] = L[u] + 1;
        if(!dfs(v, s)) return false;
    }
    return true;
}

int findk(int s, int t, int k){
    if(p[t] == -1) return -1;
    if(L[t] < k) return -1;
    if(L[t] == k) return t;
    return findk(s, p[t], k);
}

void bm(int q, int t){
    if(p[t] == -1 || !L[t]) return;
    mat[q][ L[t] ] = t;
    if(L[t] == 1) return;
    bm(q, p[t]);
}

int main(){

    scanf("%d %d %d", &n, &m, &q);

    forn(i, m){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].pb(b);
    }

    for1(i, n) sort(g[i].begin(), g[i].end());

    forn(i, q){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        w[a].eb(b, c, i);
    }

    for1(i, n) dfs2(i, i);

    for1(i, n){
        memset(p, -1, sizeof p);
        memset(L, 0, sizeof L);
        memset(mat, -1, sizeof mat);
        p[i] = i;
        L[i] = 1;
        dfs(i, i);

        for1(j, n) bm(j, j);

        int t, k, id;
        for(auto x : w[i]){
            tie(t, k, id) = x;
            ans[id] = mat[t][k];
        }
    }

    forn(i, q) printf("%d\n", ans[i]);




    return 0;
}
