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

const ll oo = 5000000000000000001;
const int N = 100005;
int n;
ll v[N], q[3];
ll a, b, c;

ll dp[N][3];

ll f(int i, int j){
    if(j == 3) return 0;
    if(i == n) return -oo;
    ll &ans = dp[i][j];
    if(~ans) return ans;

    return ans = max(f(i+1, j), q[j] * v[i] + f(i, j+1));
}

int main(){

    memset(dp, -1, sizeof dp);

    scanf("%d %lld %lld %lld", &n, q, q+1, q+2);

    ll ans = 0;

    forn(i, n) scanf("%lld", v+i);

    printf("%lld\n", f(0, 0));




    return 0;
}
