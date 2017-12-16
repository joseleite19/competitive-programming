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
const int N = 1000006;

ll fat[N], inv[N];

ll dp[N];

ll caos(int n){
    if(n < 2) return !n;
    if(~dp[n]) return dp[n];
    return dp[n] = ((n-1)*(caos(n-1) + (caos(n-2))))%MOD;
}

ll f(int n){
    ll ans = fat[n] - dp[n] - n*dp[n-1];
    return ((ans % MOD) + MOD) % MOD;
}

int main(){

    fat[0] = 1;
    for1(i, N-1) fat[i] = (i * fat[i-1]) % MOD;

    dp[0] = 1, dp[1] = 0;
    fore(i, 2, N-1) dp[i] = ((i-1)*(dp[i-2] + dp[i-1]))%MOD;

    int n;

    while(scanf("%d", &n) == 1 && n){
        printf("%lld\n", f(n));
    }


    return 0;
}

