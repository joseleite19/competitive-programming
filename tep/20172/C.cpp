#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back
#define pb push_back

using namespace std;

int main(){
    long long a, b;

    while(scanf("%lld %lld", &a, &b) == 2)
        printf("%lld\n", a^b);

    return 0;
}
