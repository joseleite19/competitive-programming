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

vector<int> g[N];

inline ll mul(ll a, ll b){ return (a * b) % MOD; }
inline ll add(ll a, ll b){ return (a + b) % MOD; }

int n, m, k;

ll dp[N][2][2][11];

ll f(int u, int p, int was, int sp, int x){    

    ll &ans = dp[u][was][sp][x];

    if(~ans) return ans;
    ans = 0;

    vector<ll> tmp(x+1, 0);
    vector<ll> tmp1(x+1), tmp3(x+1);

    tmp[0] = 1;

    ll t; int cnt = 0;
    
    for(int v : g[u]) if(v != p){ 
        cnt++;
        for(int i = 0; i <= x; i++){ // how many specials will have in subtree v
            t = f(v, u, sp, 0, i);
            tmp3[i] = t;
        }

        vector<ll> tmp1(x+1);

        for(int i = 0; i <= x; i++){
            for(int j = 0; i + j <= x; j++){
                tmp1[j+i] = add(tmp1[j+i], mul(tmp[j], tmp3[i]));
            }
        }

        swap(tmp1, tmp);
    }
    if(!cnt){ // caso base
        ans = 0;
        if(was && !x) ans = k - 1;
        if(sp && !x) ans = 1;
        if(!was && !x) ans = m - 1;
        return ans;
    }
        forn(i, x+1){
            ans = add(ans, tmp[i]);
            if(u == 1) printf("..%lld\n", ans);
        }
    ans = mul(ans, was ? k - 1 : m-1);


    return ans;
}


ll exp(ll x, ll n){
    if(n == 0) return 1;
    ll ans = exp(mul(x, x), n / 2);
    if(n & 1) ans = mul(ans, x);
    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    int x;
    scanf("%d %d", &n, &m);

    forn(i, n-1){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].pb(b), g[b].pb(a);
    }

    scanf("%d %d", &k, &x);

    ll ans = f(1, 1, 0, 0, x);


    printf("%lld\n", ans);

    return 0;
}
