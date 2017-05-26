#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;

long long dp[N];
long long cnt[N];

long long f(int i){
    if(i >= N)
        return 0;

    if(dp[i] != -1) return dp[i];
    //pega chamando i+2, ou nao pega o i, pega o i+1 e nao pega o i+2 chamando i+3
    return dp[i] = max(f(i+2) + cnt[i]*i, f(i+3) + cnt[i+1]*(i+1));
}


int main(){

    scanf("%d", &n);

    int x;

    int mn = N;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        cnt[x]++;
        mn = min(mn, x);
    }

    memset(dp, -1, sizeof dp);
    printf("%lld\n", f(mn));

    return 0;
}
