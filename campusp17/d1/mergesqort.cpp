#include <bits/stdc++.h>

using namespace std;

map<int, long long> dp;
long long f(int n){
    if(n == 1) return 0;
    if(dp.count(n)) return dp[n];
    int x = sqrt(n);
    return dp[n] = n + f(x) + f(n-x);
}

int main(){
    int n;

    scanf("%d", &n);

    printf("%lld\n", f(n));


    return 0;
}
