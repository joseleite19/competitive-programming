#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 5005;

int n;
ll v[N];

ll dp[N][6];

ll f(int i, int j){

    ll &ans = dp[i][j];

    if(~ans) return ans;

    ans = -oo;

    if(j == 3){
        ll sum = 0;
        for(int k = i; k < n; k++)
            sum += v[k];
        return ans = -sum;
    }

    if(j < 3){
        ll sum = 0;
        int s = 1;
        if(j & 1) s = -1;

        for(int k = i; k < n; k++){
            ans = max(ans, s*sum + f(k, j+1));
            sum += v[k];
        }

        ans = max(ans, s*sum + f(n, j+1));
    }
    return ans;
}

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    memset(dp, -1, sizeof dp);

    printf("%lld\n", f(0, 0));




    return 0;
}
