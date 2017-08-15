#include <bits/stdc++.h>

using namespace std;

const int N = 202;

const int L = 17222;

short int dp[2][N][L];

int ld[N], lc[N], n;

int zero = 12005;

// > 5
// < 2

short int d, c, tmp;

long long v[N];

int main(){
    int k;

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    int l = zero, r = zero;
    for(int i = 0; i < n; i++){
        while(v[i] % 2 == 0) ld[i]++, v[i] /= 2;
        while(v[i] % 5 == 0) lc[i]++, v[i] /= 5;
        l -= ld[i], r += lc[i];
    }


    for(int i = n-1; i >= 0; i--){
        
        for(int off = l; off <= r; off++) dp[i&1][0][off] = 0;

        for(int j = 1; j <= k; j++){
            for(int off = l; off <= r; off++){
                d = max(0, zero - off) + ld[i], c = max(0, off - zero) + lc[i];
                tmp = min(d, c);
                d -= tmp, c -= tmp;

                dp[i&1][j][off] = max(dp[(i+1)&1][j][off], (short int)(dp[(i+1)&1][j-1][zero - d + c] + tmp));
            }
        }
    }


    printf("%d\n", int(dp[0][k][zero]));




    return 0;
}
