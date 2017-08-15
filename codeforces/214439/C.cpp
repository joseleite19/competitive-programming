#include <bits/stdc++.h>

#define oo (1000000000000000)

using namespace std;

int n;
const int N = 100005;

long long dp[N][2];
int mark[N][2];
int v[N];

long long f(int i, int p){
    if(i == n) return p ? 0 : -oo;
    if(mark[i][p]) return dp[i][p];

    mark[i][p] = 1;

    return dp[i][p] = max(f(i+1, p), v[i] + f(i+1, (p+v[i])&1));
}


int main(){


    scanf("%d", &n);

    for(int i = 0; i < n; i++) scanf("%d", v+i);

    memset(dp, -1, sizeof dp);

    printf("%lld\n", f(0, 0));


    return 0;
}
