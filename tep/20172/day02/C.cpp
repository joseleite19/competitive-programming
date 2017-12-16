#include <bits/stdc++.h>

using namespace std;

const int N = 1000006;

typedef long long ll;

ll dp[N];

ll f(int x){
    if(~dp[x]) return dp[x];
    if(x >= 101) return dp[x] = x-10;
    return dp[x] = f(f(x+11));
}


int main(){

    memset(dp, -1, sizeof dp);

    int x;
    while(scanf("%d", &x) == 1 && x){
        printf("f91(%d) = %lld\n", x, f(x));
    }


}
