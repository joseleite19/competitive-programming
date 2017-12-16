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

ll sq(ll x){
    ll q = sqrt(x);
    while(q * q < x) q++;
    return q;
}

int main(){
    ll n;

    scanf("%lld", &n);

    ll mn = oo;
    for(ll a = 1; a <= n; a++){
        ll b = (n + a - 1) / a;
        if(a * b >= n)
            mn = min(mn, 2*(a + b));
    }

    printf("%lld\n", mn);



    return 0;
}
