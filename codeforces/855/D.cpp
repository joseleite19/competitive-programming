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
const int N = 100005;

int px[N];
int fd(int x){ return x == px[x] ? x : px[x] = fd(px[x]); }
int n;
vector<int> g[N], g2[N];
int p[N], p2[N], L[N], L2[N], pi[N], ty[N];
int dp[N][20];

void dfs(int u){
    for(int v : g[u]){
        p[v] = u;
        L[v] = L[u]+1;
        dfs(v);
    }
}

int up(int u, int w){
    if(w == 0) return p[u];
    if(~dp[u][w]) return dp[u][w];
    return dp[u][w] = up(up(u, w-1), w-1);
}

int LCA(int u, int v){
    if(!L[u] || !L[v]) return 0;
    if(L[u] < L[v]) swap(u, v);

    ford(i, 20){
        if(L[u] - (1 << i) >= L[v])
            u = up(u, i);
    }
    if(u == v) return u;

    ford(i, 20){
        if((1 << i) >= L[u] && up(u, i) != up(v, i))
            u = up(u, i), v = up(v, i);
    }

    return p[u];
}

int dp2[N][20];

void dfs2(int u){
    for(int v : g2[u]){
        p2[v] = u;
        L2[v] = L2[u]+1;
        dfs2(v);
    }
}

int up2(int u, int w){
    if(w == 0) return p[u];
    if(~dp2[u][w]) return dp2[u][w];
    return dp2[u][w] = up2(up2(u, w-1), w-1);
}

int LCA2(int u, int v){
    if(!L2[u] || !L2[v]) return 0;
    if(L2[u] < L2[v]) swap(u, v);

    ford(i, 20){
        if(L2[u] - (1 << i) >= L2[v])
            u = up2(u, i);
    }

    if(u == v) return u;

    ford(i, 20){
        if((1 << i) >= L2[u] && up2(u, i) != up2(v, i))
            u = up2(u, i), v = up2(v, i);
    }

    return p2[u];
}

int main(){
    memset(dp, -1, sizeof dp);
    memset(dp2, -1, sizeof dp2);
    forn(i, N) px[i] = i;

    scanf("%d", &n);

    int root = -1;
    for1(i, n){
        scanf("%d %d", pi+i, ty+i);
        if(pi[i] == -1) root = root != -1 ? 0 : i;
        else{
            g[ pi[i] ].pb(i);
            if(ty[i] == 1) px[i] = fd(pi[i]);
        }
    }

    for1(i, n){
        if(pi[i] == -1) continue;
        if(fd(i) != fd(pi[i])) g2[ fd(pi[i]) ].pb(fd(i));
    }
    
    L[root] = L2[fd(root)] = 1;
    dfs(root), dfs2(fd(root));

    int q;

    scanf("%d", &q);
    int a, b, c;
    while(q--){
        scanf("%d %d %d", &a, &b, &c);
        if(a == 2) printf("%s\n", b != c && LCA2(fd(b), fd(c)) == fd(c) ? "YES" : "NO");
        else printf("%s\n", b != c && LCA(b, c) == b ? "YES" : "NO");
    }



    return 0;
}
