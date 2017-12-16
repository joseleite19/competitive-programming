#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

const int N = 1000006;

typedef long long ll;

pair<ll, ll> f(ll n){
    ll lo = 0, hi = 1000000007;

    while(lo+1 < hi){
        ll mid = (lo + hi) / 2;
        printf("%lld %lld %lld %lld\n", lo, hi, mid, mid*(mid-1)/2);
        if(mid * (mid+1) / 2 < n) lo = mid;
        else hi = mid-1;
    }
    if(hi * (hi+1) >= n) hi = lo;


    hi++;
    ll x = n - hi * (hi-1) / 2;

    printf("%lld %lld\n", x, hi);
    return make_pair(hi - x + 1, hi);
}

int main(){

    int line = 1;
    int n = 1;

    ll x;
    while(scanf("%lld", &x) == 1){
        pair<ll, ll> p = f(x);
        printf("%lld/%lld\n", p.ff, p.ss);
    }
}
