#include <bits/stdc++.h>

#define MOD 1000000007LL

using namespace std;

typedef long long ll;

ll CC[111][111];

ll C(int n, int k){
    if(n == k || n == 0 || k == 0) return 1;
    if(~CC[n][k]) return CC[n][k];
    return CC[n][k] = (C(n-1, k-1) + C(n-1, k)) % MOD;
}

int n, k;
ll dp[111][111];

ll f(int id, int spaces){
    if(id == n) return spaces == 0;

    ll &ans = dp[id][spaces];

    if(~ans) return ans;

    ans = 0;

    for(int g = 0; g < k; g++) if(g <= spaces){
        ll tmp = (C(spaces, g)*f(id+1, spaces-g)) % MOD;
        ans = (ans + tmp) % MOD;
    }
    return ans;
}

int main(){

    memset(CC, -1, sizeof CC);
    memset(dp, -1, sizeof dp);

    scanf("%d %d", &n, &k);

    if(n == 1) return printf("1\n"), 0;

    if(k == 1 && n > 2) return printf("0\n"), 0;

    printf("%lld\n", f(0, n-2));

    return 0;
}
