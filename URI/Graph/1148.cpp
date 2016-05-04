#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 1000000000
#define MAXN 500

int main(){
    int n, e, dp[MAXN+1][MAXN+1], x, y, h, k, o, d;

    while(scanf("%d %d", &n, &e) == 2 && n + e){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = INF;

        for(int i = 0; i < e; i++){
            scanf("%d %d %d", &x, &y, &h);
            dp[x][y] = h;
        }

        for(int i = 1; i <= n; i++)
            for(int j = i+1; j <= n; j++)
                if(dp[i][j] != INF && dp[j][i] != INF)
                    dp[i][j] = dp[j][i] = 0;

        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

        scanf("%d", &k);
        while(k--){
            scanf("%d %d", &o, &d);
            if(dp[o][d] != INF) printf("%d\n", dp[o][d]);
            else printf("Nao e possivel entregar a carta\n");
        }
        printf("\n");
    }

    return 0;
}
