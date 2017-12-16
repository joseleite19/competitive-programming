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

int ini[N], go[N];
vector<int> g[N];

int picked[N];

int dfs(int u, int p, int l, int ll){
    int ans = 0;
    if(ini[u] ^ l != go[u]){
        ans++;
        l ^= 1;
        picked[u] = 1;
    }

    for(int v : g[u]) if(v != p){
        ans += dfs(v, u, ll, l);
    }
    return ans;
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

    for1(i, n) scanf("%d", ini+i);
    for1(i, n) scanf("%d", go+i);

    printf("%d\n", dfs(1, 1, 0, 0));

    for1(i, n) if(picked[i])
        printf("%d\n", i);



    return 0;
}
