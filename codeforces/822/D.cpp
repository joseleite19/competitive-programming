#include <bits/stdc++.h>

#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
#define oo 20000000000000000
#define mp make_pair
#define MOD (1000000007)
using namespace std;

const int N = 5000006;

int d[N];

long long dp[N];
long long f(int n){
    if(n == 1) return 0;
    if(~dp[n]) return dp[n];

    return dp[n] = (1LL*n*(d[n]-1)/2 + f(n/d[n])) % MOD;
}



int main(){

    memset(dp, -1, sizeof dp);

    for(int i = 2; i < N; i++) if(!d[i]){
        for(int j = i; j < N; j += i) if(!d[j])
            d[j] = i;
    }

    int l, r;
    long long t;

    scanf("%lld %d %d", &t, &l, &r);

    long long b = 1;

    long long ans = 0;

    for(int i = l; i <= r; i++){
        long long tmp = (b*f(i)) % MOD;
        ans = (ans + tmp) % MOD;

        b = (b * t) % MOD;
    }

    printf("%lld\n", ans);

    return 0;
}
