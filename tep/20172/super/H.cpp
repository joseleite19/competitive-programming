#include <bits/stdc++.h>

using namespace std;

long long dp[1000][1000];

long long f (long long len, long long deep) {
    //printf("%lld %lld\n", len, deep);
    if (not deep and not len) return 1; // se achou algum com profundidade certa e pegou todos os parenteses
    if (len <= 0 || deep <= 0) return 0; // se usou
    if (~dp[len][deep]) return dp[len][deep];
    long long comp = 0;
    for (auto i = 1; i < len/2; i++) {
        comp += f(i*2, deep);
    }
    return dp[len][deep] = f(len-2, deep-1) + comp; 
}

int main () {
    long long len, deep;
    while (scanf("%lld %lld", &len, &deep)) {
        for (auto i = 0; i < 1000; i++) {
            for (auto j = 0; j < 1000; j++) {
                dp[i][j] = -1;
            }
        }
        printf("%lld\n", f(len, deep));
    }
}
