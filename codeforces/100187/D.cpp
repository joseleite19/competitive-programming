#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 200005;

ll f(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e & 1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ans;
}

ll fat[N];
ll C(int n, int k){
    ll ans = (fat[n] * f(fat[n-k], MOD-2)) % MOD;
    ans = (ans * f(fat[k], MOD-2)) % MOD;
    return ans;
}

ll g(ll x){
    return (f(2, x) - 1 + MOD) % MOD;
}

int main(){
    fat[0] = 1;

    for(int i = 1; i < N; i++)
        fat[i] = (i * fat[i-1]) % MOD;

    int n;

    scanf("%d", &n);

    ll ans = 0;

    for(int i = 1; i < n; i++)
        ans = (ans + C(n, i) * g(n-i)) % MOD;

    printf("%lld\n", ans);
    return 0;
}
