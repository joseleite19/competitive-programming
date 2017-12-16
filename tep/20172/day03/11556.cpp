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

    ll a, b;

    while(scanf("%lld %lld", &a, &b) == 2)
        printf("%s\n", (1LL << (b+1))-1 >= a ? "yes" : "no" );



    return 0;
}
