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
const int N = 1005;

ll dp[N][N];

ll C(int n, int k){
    if(n == k || !n || !k) return 1;
    if(~dp[n][k]) return dp[n][k];
    return dp[n][k] = (C(n-1, k-1) + C(n-1, k)) % MOD;
}

ll f(int n, int k){
    if(!k) return 1;
    ll ans = 0;

    while(n >= k){
        ans = (ans + C(n, k)) % MOD;
        n--, k++;
    }
    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);

    int n, k;

    while(scanf("%d %d", &n, &k) == 2)
        printf("%lld\n", f(n, k));


    return 0;
}
