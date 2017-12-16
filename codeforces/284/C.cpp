#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000009LL
#define ll long long
using namespace std;

int main(){

    ll x;

    scanf("%lld", &x);

    ll a = 0, b = 0;

    while(a <= x) a += ++b;
    a -= b--;

    printf("%lld\n%lld\n", a, b);

    
    return 0;
}
