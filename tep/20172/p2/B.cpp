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
const int N = 105;

ll dp[N];

ll f(int n){
    if(n == 0 || n == 1) return 1;
    if(~dp[n]) return dp[n];
    return dp[n] = f(n-1) + f(n-2);
}

int main(){
    memset(dp, -1, sizeof dp);

    int t;

    scanf("%d", &t);

    int n;
    for1(tc, t){
        scanf("%d", &n);

        printf("Caso %d: %lld\n", tc, f(n));
    }



    return 0;
}
