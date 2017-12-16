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

const ll oo = 100000000000000000;
const int N = 1596;
const int W = 70000;

int d[N];
ll p[N][60];
int sz;

void file(){
    freopen("divisors.in", "r", stdin);
    freopen("divisors.out", "w", stdout);
}

inline int LG(ll x){
    return 63 - __builtin_clzll(x);
}

inline bool over(ll a, ll b){
    return LG(a) + LG(b) >= 55;
}

ll dp[W+2][22];

ll f(int n, int j){
    // if(j > 20) printf("asd\n");
    if(n == 1) return 1;
    if(j == sz) return oo;
    ll &ans = dp[n][j];
    if(~ans) return ans;
    ans = oo;

    ll t, a, k;
    for(int i = 1; i*i <= n; i++) if(n % i == 0){
        k = i;
        if(k-2 < 60 && k >= 2 && !over(p[j][k-2], f(n / i, j+1))){
            ans = min(ans, p[j][k-2] * f(n / i, j+1));
        }
        k = n / i;
        if(k-2 < 60 && k >= 2 && !over(p[j][k-2], f(i, j+1))){
            ans = min(ans, p[j][k-2] * f(i, j+1));
        }
    }
    return ans;
}


int main(){
    file();
    memset(dp, -1, sizeof dp);

    for1(i, N){
        for(int j = i; j < N; j += i)
            d[j]++;
    }

    forn(i, N) forn(j, 60) p[i][j] = oo;

    sz = 0;
    for1(i, N) if(d[i] == 2){
        p[sz][0] = i;
        for1(j, 59){
            if(over(i, p[sz][j-1])) break;
            p[sz][j] = p[sz][j-1] * i;
        }
        sz++;
    }
    cerr << sz << endl;

    ll n;

    // ll x = 0;
    // ford(i, W){
    //     x += f(i, 0);
    // }

    // cerr << x << endl;

// return 0;
    scanf("%lld", &n);



    ford(i, W){
        if(f(i, 0) <= n){
            printf("%lld\n", f(i, 0));
            break;
        }
    }



    return 0;
}
