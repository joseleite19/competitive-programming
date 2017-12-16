#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;

ll D(ll a, ll b, ll c, ll d, ll e, ll f){
    return a*d + c*f + b*e - (c*b + e*d + f*a);
}

inline ll sq(ll x){
    return x * x;
}

int main(){

    ll a, b, c, d, e, f;

    scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
    bool ans = D(a, b, c, d, e, f) != 0;

    ans &= sq(a - c) + sq(b - d) == sq(c - e) + sq(d - f);

    printf("%s\n", ans ? "Yes" : "No");


    return 0;
}
