#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define MOD 1000000007LL

using namespace std;

typedef long long ll;

int main(){

    ll x;

    while(scanf("%lld", &x) == 1)
        printf("%lld\n", x*(x+1)/2 * x*(x+1)/2);


    return 0;
}
