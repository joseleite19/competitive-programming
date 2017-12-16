#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000LL
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll oo = 1000000000000000000;
const int N = 100005;

int a, b, n, k;

inline ll add(ll a, ll b){ return (a + b) % MOD; }

pll operator *(const pll &x, const pll &y){
    return pll(add(x.ff*y.ff, x.ss*y.ss*b), add(x.ff*y.ss, x.ss*y.ff));
}

pll f(pll x, int n){
    if(n == 0) return pll(1, 0);
    pll c = f(x * x, n/2);
    if(n & 1) c = c * x;
    return c;
}

int main(){

    scanf("%d %d %d %d", &a, &b, &n, &k);

    ll ans = 2*f(pll(a, 1), n).ff;

    if(a * a > b || (n % 2 == 0 && a * a < b))
        ans = add(ans, MOD-1);

    while(k > 1) ans /= 10, k--;

    printf("%lld\n", ans % 10);

    return 0;
}
