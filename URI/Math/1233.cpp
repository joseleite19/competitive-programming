#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll tot(ll x){
    ll ans = 1;
    for(ll i = 2; i*i <= x; i++){
        if(x % i == 0){
            ll tmp = 1;
            x /= i;
            while(x % i == 0) x /= i, tmp *= i;
            ans *= (i-1)*tmp;
        }
    }
    if(x > 1) ans *= (x - 1);
    return ans;
}

int main(){
    ll x;

    while(scanf("%lld", &x) == 1)
        printf("%lld\n", (tot(x)+1)/2);


}
