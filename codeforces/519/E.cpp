
#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
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

int n;
vector<int> g[N];
int L[N], p[N], sz[N], dp[N][22];

int dfs(int u){
    sz[u] = 1;
    for(int v : g[u]) if(v != p[u]){
        p[v] = u, L[v] = L[u]+1;
        sz[u] += dfs(v);
    }
    return sz[u];
}

int up(int u, int i){
    if(i == 0) return p[u];
    if(~dp[u][i]) return dp[u][i];
    return dp[u][i] = up(up(u, i-1), i-1);
}

int LCA(int u, int v){
    if(L[u] < L[v]) swap(u, v);

    ford(i, 20){
        if(L[u] - (1 << i) >= L[v]){
            u = up(u, i);
        }
    }

    if(u == v) return u;

    ford(i, 20){
        if(L[u] >= (1 << i) && up(u, i) != up(v, i))
            u = up(u, i), v = up(v, i);
    }
    return p[u];
}

int D(int u, int v){
    return L[u] + L[v] - 2*L[ LCA(u, v) ];
}

int f(int u, int v, int d){
    d /= 2;
    d--;
    ford(i, 20){
        if(d >= (1 << i)){
            d -= 1 << i;
            u = up(u, i), v = up(v, i);
        }
    }
    return n - sz[u] - sz[v];
}

int f2(int u, int v, int d){
    d /= 2;
    d--;

    if(L[u] < L[v]) swap(u, v);
    ford(i, 20){
         if(d >= (1 << i)){
            d -= 1 << i;
            u = up(u, i);
         }
    }

    return sz[ p[u] ] - sz[u];
}

int main(){
    memset(dp, -1, sizeof dp);

    scanf("%d", &n);

    forn(i, n-1){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].pb(b), g[b].pb(a);
    }
    L[1] = p[1] = 1;
    dfs(1);

    int m, a, b;

    scanf("%d", &m);

    while(m--){
        scanf("%d %d", &a, &b);

        if(a == b){ printf("%d\n", n); continue; }

        int d = D(a, b);

        if(d & 1){
            printf("0\n"); continue;
        }

        if(L[a] == L[b]) printf("%d\n", f(a, b, d));
        else printf("%d\n", f2(a, b, d));
    }


    return 0;
}
