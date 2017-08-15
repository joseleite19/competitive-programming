#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 100000000000000000

using namespace std;

const int N = 1000006;

int n;
long long v[N];
long long dp[N][7];

long long f(int i, int p){
    if(i == n) return p == 0 ? 0 : -oo;
    if(~dp[i][p]) return dp[i][p];
    return dp[i][p] = max(f(i+1, p), v[i] + f(i+1, (p+v[i])%7));
}


int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    memset(dp, -1, sizeof dp);
    printf("%lld\n", f(0, 0));


    return 0;
}
