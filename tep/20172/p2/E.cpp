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
const int N = 22005;

ll dp[N][321];

inline ll add(ll a, ll b){ return (a+b) >= MOD ? a + b - MOD : a + b; }

ll f(int n, int m){
    if(!n) return 1;
    if(n < 0 || !m) return 0;
    if(~dp[n][m]) return dp[n][m];
    return dp[n][m] = add(f(n-m, m), f(n, m-1));
}

int main(){
    memset(dp, -1, sizeof dp);

    int n, m, k;

    while(scanf("%d %d %d", &n, &m, &k) == 3)
        printf("%lld\n", f(n - m*k, m));

    return 0;
}
