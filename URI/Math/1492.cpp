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

ll f(ll x){
    ll ans = 0;
    for(int i = 60; i > 0; i--) if(x & (1LL << i)){
        ans += (1LL << (i-1))*i;
        x -= (1LL << i);
        ans += x+1;
    }
    if(x) ans++;
    return ans;
}

int main(){
    ll a, b;

    while(scanf("%lld %lld", &a, &b) == 2)
        printf("%lld\n", f(b) - f(a-1));


    return 0;
}
