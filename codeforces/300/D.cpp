#include <bits/stdc++.h>

#define MOD 7340033

using namespace std;

const int N = 1000006;

long long a, b, n, fat[N];

map<int, int> dp;

long long solve(int n, int k){
    if(dp.count(n * N + k)) return dp[n*N + k];
    printf("%d %d\n", n, k);
    if(k < 0) return 0;
    if(k == 0) return 1;
    if(n % 2 == 0 || n == 1) return 0;
    if(n == 3) return solve(n / 2, k-1);
    long long ans = 0;
    ans = (ans + 4*solve(n/2, k-1)) % MOD; // pegando 1
    for(int i = 1; i < k-1; i++){
       ans = (ans + solve(n / 2, i) + solve(n / 2, k-1-i) ) % MOD; // pegando 2
    }

    for(int i = 1; i < k-2; i++){
        for(int j = 1; j < k-2; j++){
            ans = (ans + solve(n / 2, i) + solve(n / 2, j) + solve(n - 2, k-2-i-j)) % MOD; //pegando 3
        }
    }

    for(int i = 1; i < k-3; i++){
        for(int j = 1; j < k-3; j++){
            for(int q = 1; q < k-3; q++){
                ans = (ans + solve(n / 2, i) + solve(n / 2, j) + solve(n / 2, q) + solve(n / 2, k-3 - i - j - q)) % MOD; // pegando 4
            }
        }
    }
    return dp[n*N + k] = ans;
}



int main(){

    int q;

    scanf("%d", &q);

    int n, k;
    while(q--){
        scanf("%d %d", &n, &k);
        printf("%lld\n", solve(n, k));
    }


    return 0;
}
