#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define ep emplace
#define MOD 1000000009LL

using namespace std;

typedef unsigned long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;


int main(){
    ll a, b, x, j, t;

    for(int tc = 1; scanf(" %lld,%lld %lld %lld", &a, &b, &j, &t) == 4; tc++){
        x = a * 100 + b;
        j /= 100;
        while(t--){
            x += x * j;
        }
        printf("Case #%lld: R$ %lld,%02d\n", tc, x / 100, x % 100);
    }

    return 0;
}
