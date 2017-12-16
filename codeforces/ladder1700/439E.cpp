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

ll phi[N], p[N];

ll fat[N];

ll f(ll x, ll e){
    ll ans = 1; x %= MOD;
    while(e){
        if(e & 1) ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        e >>= 1;
    }
    return ans;
}

ll C(int n, int k){
    return (fat[n] * f(fat[n-k] * fat[k], MOD-2)) % MOD;
}

int main(){

    forn(i, N) phi[i] = i;

    fore(i, 2, N-1) if(phi[i] == i){
        phi[i] = i - 1;
        for(int j = i + i; j < N; j += i)
            phi[j] = phi[j] * (i - 1) / i;
    }

    fat[0] = 1;
    for1(i, N-1) fat[i] = (fat[i-1] * i) % MOD;

    int q, n, f;

    scanf("%d", &q);

    while(q--){
        scanf("%d %d", &n, &f);

        if(f == 1){
            printf("1\n"); continue;
        }
        if(f == 2){
            ll ans = 0;
            for1(i, n) ans = (ans + phi[i]) % MOD;
            printf("%lld\n", ans);
            continue;
        }
        ll ans = 0;



    }



    return 0;
}
