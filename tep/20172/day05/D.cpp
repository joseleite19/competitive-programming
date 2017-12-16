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

const ll oo = 1000000000000000000;
const int N = 100005;

ll f2(ll x){
    ll ans = 0, t;

    for(int f = 1; f*3 < x; f++){
        t = x - f - f - f- 1;
        if(t < 0) break;
        ans += t / 2;
    }
    return ans;
}

ll g(ll x){
    return (x-1)*(x-2)/2;
}

ll f(ll x){
    x -= 3;
    return 1 + g(x) / 6;
}

int main(){
    ll n;

    for(int tc = 1; scanf("%lld", &n) == 1 && n; tc++)
        printf("Case %d: %lld\n", tc, f(n));


    return 0;
}
