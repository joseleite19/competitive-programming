#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 1000006;

char s[N], t[N];

ll dp[N][2];

ll f(int x, int m){
    if(x == 0) return 1;
    ll &ans = dp[x][m];
    if(~ans) return ans;
    if(m) return ans = f(x-1, 0);
    return ans = f(x-1, 0) + f(x-1, 1);
}

int main(){
    memset(dp, -1, sizeof dp);
    int x;
    while(scanf(" %d", &x) == 1 && x){
        printf("%lld\n", f(x, 1));
    }


    return 0;
}
