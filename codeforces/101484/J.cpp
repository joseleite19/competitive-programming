#include <bits/stdc++.h>

#define ff first
#define ss second
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define MOD 1000000007LL

using namespace std;
typedef long long ll;

ll f(ll a, ll b, ll c){
    return a + b + c - 2*max(a, max(b, c));
}

int main(){

    ll a, b;

    scanf("%lld %lld", &a, &b);

    printf("%lld\n", max(a, b));

    return 0;
}
