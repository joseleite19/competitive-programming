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
typedef pair<ll, ll> pll;
const ll oo = 1000000000000000000;
const int N = 100005;

pll dp[N][2];

int n;

ll v[N];

pll maxa(pll a, pll b){
    return max(a, b);
}

pll maxb(pll a, pll b){
    swap(a.ff, a.ss), swap(b.ff, b.ss);
    a = max(a, b);
    swap(a.ff, a.ss);
    return a;
}

pll operator+(const pll &q, const pll &o){
    return mp(q.ff + o.ff, q.ss + o.ss);
}

pll f(int i, int q){
    if(i == n) return mp(0, 0);
    pll &ans = dp[i][q];
    if(ans.ff != -1) return ans;
    
    if(q) return ans = maxb(f(i+1, 0) + mp(0, v[i]), f(i+1, 1) + mp(v[i], 0));
    else return ans = maxa(f(i+1, 1) + mp(v[i], 0), f(i+1, 0) + mp(0, v[i]));
}


int main(){

    memset(dp, -1, sizeof dp);

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    pll ans = f(0, 1);

    printf("%lld %lld\n", ans.ff, ans.ss);


    return 0;
}
