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

bool is_lucky(int x){
    while(x){
        if(x % 10 != 4 && x % 10 != 7) return 0;
        x /= 10;
    }
    return 1;
}

vector<int> g[N];
int n, sz[N];

int dfs(int u, int p){
    sz[u] = 1;
    for(int v : g[u]) if(v != p)
        sz[u] += dfs(v, u);

    return sz[u];
}


int main(){

    scanf("%d", &n);

    forn(i, n-1){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(!is_lucky(c))
            g[a].eb(b), g[b].eb(a);
    }

    ll ans = 0;

    for1(i, n) if(!sz[i]){
        ll k = dfs(i, i);
        ans += k * (n - k) * (n - k - 1);
    }

    printf("%lld\n", ans);


    return 0;
}
