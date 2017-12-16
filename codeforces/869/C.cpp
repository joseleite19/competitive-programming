#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 998244353LL
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

ll fat[N];

ll pot(ll x, ll e){
    ll ans = 1; x %= MOD;
    while(e){
        if(e & 1) ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        e >>= 1;
    }
    return ans;
}

ll C(int n, int k){
    return (fat[n] * pot(fat[k] * fat[n-k], MOD-2)) % MOD;
}

ll good(ll a, ll b){
    if(a > b) swap(a, b);
    ll ans = 0;
    forn(i, a+1) ans = (ans + ((C(b, i)*C(a, i))%MOD)*fat[i]) % MOD;
    return ans;
}

ll f(ll a, ll b, ll c){
    ll ans = 0;

    ans = (good(a, b) * good(b, c)) % MOD;
    ans = (ans * good(c, a)) % MOD;

    return ans;
}

int main(){

    fat[0] = 1;

    for1(i, N-1) fat[i] = (i * fat[i-1]) % MOD;

    ll a, b, c;

    scanf("%lld %lld %lld", &a, &b, &c);

    ll ans = f(a, b, c) % MOD;

    printf("%lld\n", ans);



    return 0;
}
