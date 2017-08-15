#include <bits/stdc++.h>

using namespace std;

long long dp[44][44][44];
int n;
long long f(int i, int c, int ja){
    if(i == n) return ja;

    if(~dp[i][c][ja]) return dp[i][c][ja];

    return dp[i][c][ja] = f(i+1, c+1, ja || c >= 2) + f(i+1, 0, ja);
}

long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    while(scanf("%d", &n) == 1){
        memset(dp, -1, sizeof dp);
        long long a = (1LL << n) - f(0, 0, 0), b = 1LL << n;
        long long g = gcd(a, b);
        a /= g, b /= g;
        printf("%lld/%lld\n", a, b);
    }


    return 0;
}
