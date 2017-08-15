#include <bits/stdc++.h>

#define MOD (1000000007)

using namespace std;

const int N =100005;

long long v[N];
int n;


int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    long long sum = 0;

    long long pot = 1;
    for(int i = 0; i < n; i++)
        sum += v[i];
    for(int i = 1; i < n; i++)
        pot = (2*pot) % MOD;

    sum %= MOD;

    printf("%lld\n", (sum * pot - sum + MOD) % MOD);


    return 0;
}
