#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, n;

int LG(ll x){
    return 63 - __builtin_clzll(x);
}

ll find(ll a, ll b, ll n){
    ll lo = b, hi = 1e12;
    while(lo + 1 < hi){
        ll mid = (lo + hi)/2;
        if(LG(a) + LG(mid) > LG(6*n)) hi = mid-1;
        else if(a * mid >= 6*n) hi = mid;
        else if(a * mid < 6*n) lo = mid+1;
    }
    if(a * lo < 6*n) lo = hi;
    return lo;
}

int main(){

    scanf("%lld %lld %lld", &n, &a, &b);

    if(a * b >= 6*n) return printf("%lld\n%lld %lld\n", a*b, a, b), 0;

    pair<ll, ll> ans;
    ans.first = ans.second = 1e9;
    for(ll aa = min(a, b); aa * aa <= 60*n; aa++){
        ll bb = (6LL*n + aa - 1)/aa;
        if(bb >= max(a, b)){
            if(ans.first * ans.second > aa * bb)
                ans.first = aa, ans.second = bb;
            /*printf("%lld\n", aa * bb);
            if(a > b) printf("%lld %lld\n", bb, aa);
            else printf("%lld %lld\n", aa, bb);
            return 0;*/
        }
    }
            printf("%lld\n", ans.first * ans.second);
            if(a > b) printf("%lld %lld\n", ans.second, ans.first);
            else printf("%lld %lld\n", ans.first, ans.second);
            return 0;

    {
        ll tmp = 6*n;
        for(ll i = 2; i*i <= tmp; i++){
            if(tmp % i == 0){
                if(a > b){
                    if(tmp / i >= a && i >= b)
                        return printf("%lld\n%lld %lld\n", tmp, tmp / i, i), 0;
                }
                else{
                    if(tmp / i >= b && i >= a)
                        return printf("%lld\n%lld %lld\n", tmp, i, tmp / i), 0;
                }
            }
        }
    }

    if(a > b) a = find(b, a, n);
    else b = find(a, b, n);

    printf("%lld\n%lld %lld\n", a*b, a, b);

    return 0;
}
