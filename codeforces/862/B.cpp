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
const int N = 100005;

vector<int> g[N];

int vis[N];
int v[2];
void dfs(int u, int w){
    vis[u] = 1;
    v[w]++;
    for(int v : g[u]) if(!vis[v]){
        dfs(v, w^1);
    }
}

int main(){
    int n;

    scanf("%d", &n);

    forn(i, n-1){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(1, 0);

    printf("%lld\n", 1LL*v[0]*v[1] - (n-1));


    return 0;
}
