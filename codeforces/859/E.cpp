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
#define fore(i, n) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 200005;

int vis[N], sz[N];

vector<int> g[N];

bool dfs(int u){
    vis[u] = sz[u] = 1;
    int cnt = 0;
    for(int v : g[u]){
        if(vis[v]){ cnt++; continue; }
        if(dfs(v)) return true;
        sz[u] += sz[v];
    }
    return cnt >= 2;
}

int main(){
    int n;

    scanf("%d", &n);

    int a, b;

    ll ans = 1;
    forn(i, n){
        scanf("%d %d", &a, &b);
        if(a != b)
            g[a].pb(b), g[b].pb(a);
    }

    debug(ans);
    
    for1(i, 2*n) if(!vis[i]){
        if(dfs(i)) ans = (ans * 2) % MOD;
        else ans = (ans * sz[i]) % MOD;
    }

    printf("%lld\n", ans);


    return 0;
}
