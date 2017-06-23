#include <bits/stdc++.h>

#define MOD (1000000007)

using namespace std;

int n, k, d;

long long dp[222][222];

long long f(int sum, bool ja){
    if(sum > n) return 0;
    if(sum == n) return ja;
    
    if(~dp[sum][ja]) return dp[sum][ja];

    long long ans = 0;
    for(int q = 1; q <= k; q++)
        ans = (ans + f(sum + q, ja || q >= d)) % MOD;

    return dp[sum][ja] = ans;
}


int main(){

    scanf("%d %d %d", &n, &k, &d);

    memset(dp, -1, sizeof dp);

    printf("%lld\n", f(0, 0));

    return 0;
}
