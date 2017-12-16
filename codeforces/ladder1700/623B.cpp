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

int n, v[N];
ll a, b;
int p;
ll dp[N][10];
int mark[N][10], pass;
// 001 = começou a apagar
// 010 = terminou de apagar
// 100 = pegou alguem

ll f(int i, int bit){
    if(i == n){
        if(bit & 4) return 0;
        return oo;
    }

    ll &ans = dp[i][bit];
    if(mark[i][bit] == pass) return ans;
    mark[i][bit] = pass;

    ans = oo;

    if(v[i] % p == 0){
        if(bit & 1) return ans = min(a+f(i+1, bit), f(i+1, bit | 6));
        return ans = f(i+1, bit | 4);
    }

    int nbit = bit;
    if(bit & 1) nbit |= 2;
    
    if((v[i]+1) % p == 0) ans = min(ans, b+f(i+1, nbit | 4));
    if((v[i]-1) % p == 0) ans = min(ans, b+f(i+1, nbit | 4));

    if(bit & 2) return ans;

    ans = min(ans, a + f(i+1, bit | 1));

    return ans;
}

vector<int> primes(int x){
    vector<int> ans;
    for(ll w = 2; w * w <= x; w++){
        if(x % w == 0){
            ans.pb(w);
            while(x % w == 0) x /= w;
        }
    }
    if(x > 1) ans.pb(x);
    return ans;
}

int main(){

    scanf("%d %lld %lld", &n, &a, &b);

    forn(i, n) scanf("%d", v+i);

    ll ans = oo;

    set<int> candidates;

    for(int x : primes(v[0]    )) candidates.insert(x);
    for(int x : primes(v[0] - 1)) candidates.insert(x);
    for(int x : primes(v[0] + 1)) candidates.insert(x);
    for(int x : primes(v[n-1]  )) candidates.insert(x);
    for(int x : primes(v[n-1]-1)) candidates.insert(x);
    for(int x : primes(v[n-1]+1)) candidates.insert(x);

    for(int x : candidates) p = x, pass++, ans = min(ans, f(0, 0));

    printf("%lld\n", ans);

    return 0;
}
