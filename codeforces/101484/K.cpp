#include <bits/stdc++.h>

#define ff first
#define ss second
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define MOD 1000000007LL

using namespace std;
typedef long long ll;

const int N = 1 << 21;

int v[N], m;


ll vis[N], dp[N];

bitset<N> bbb[N];

ll f(int x){
    if(x == (1 << m) -1) return 0;
    ll &ans = dp[x];
    if(~ans) return ans;
    ans = 0;
    for(int i = 0; i < m; i++) if(((x >> i)&1) == 0){
        if(x == 1) printf("..%d %lld %lld\n", x + (1 << i), vis[x + (1 << i)], f(x + (1 << i)));
        ans += vis[x + (1 << i)] + f(x + (1 << i));
        break;
    }
    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);

    int n;

    scanf("%d %d", &n, &m);

    ll ans = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", v+i);
        vis[ v[i] ]++;
        //ans += add(v[i]);
    }

    sort(v, v+n); reverse(v, v+n);


    for(int i = 0; i < n; i++){
        printf("%d %lld\n", v[i], f(v[i]));
        ans += f(v[i]);
    }

    printf("%lld\n", ans);

    return 0;
}
