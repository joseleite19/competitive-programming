#include <bits/stdc++.h>

using namespace std;

const int N = 8008;
typedef long long ll;

int n, k, v[N];
ll dp[N];


int main(){
    memset(dp, -1, sizeof dp);

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    sort(v, v+n);

    ll ans = 0;

    for(int i = 0; i < k-1; i++)
        ans += v[n-1-i];
    for(int i = 0; i <= n-k; i++){
        ans += 1LL * v[i] * (n - k + 1);
    }

    printf("%lld\n", ans);

    return 0;
}
