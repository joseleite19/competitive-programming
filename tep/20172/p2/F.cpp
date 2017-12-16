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
const int N = 10005;

int v[N], sz;
ll dp[70][2][70];
int mark[70][2][70], pass;

ll f(int i, int less, int k){
    if(i == sz) return k == 0;

    ll &ans = dp[i][less][k];
    if(mark[i][less][k] == pass) return ans;
    mark[i][less][k] = pass;

    ans = 0;
    if(less){ 
        ans += f(i+1, 1, k); // botando 0;
        if(k) ans += f(i+1, 1, k-1); // botando 1;
    }
    else{
        ans += f(i+1, v[i], k); // botando 0;
        if(k && v[i]) ans += f(i+1, 0, k-1); // botando 1;
    }
    return ans;
}

ll solve(ll n, int k){
    pass++;
    sz = 0;
    while(n) v[sz++] = n & 1, n >>= 1;
    reverse(v, v+sz);
    return f(0, 0, k);
}

int main(){

    ll a, b;
    int k;

    for(int tc = 1; scanf("%lld %lld %d", &a, &b, &k) == 3; tc++){
        printf("Caso %d: %lld\n", tc, solve(b, k) - solve(a-1, k));
    }


    return 0;
}
