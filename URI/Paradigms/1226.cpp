#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int v[33];
int pass;

ll dp[33][2][2];
ll mark[33][2][2];

ll f(int i, int wasone, int less){
    if(i == 0) return 1;
    
    if(mark[i][wasone][less] == pass) return dp[i][wasone][less];
    mark[i][wasone][less] = pass;

    ll &ans = dp[i][wasone][less];
    ans = 0;

    for(int d = 0; d <= 9; d++){
        if(wasone && d == 3) continue;
        if(d == 4) continue;
        if(!less && d > v[i]) break;
        if(!less && d ==v[i]){
            ans += f(i-1, d==1, 0);
            break;
        }
        ans += f(i-1, d==1, 1);
    }
    
    return ans;
}

ll F(ll x){
    ll val = x;
    int i;
    for(i = 1; val; i++, val /= 10)
        v[i] = val % 10;
    pass++;
    return f(i-1, 0, 0)-1;
}

ll solve(ll x){
    ll hi = 10000000000000000000UL, lo = 1;

    while(lo + 1 < hi){
        ll mid = (hi - lo)/2 + lo;
        ll cnt = F(mid);
        if(cnt < x) lo = mid+1;
        else if(cnt > x) hi = mid-1;
        else hi = mid;
    }
    if(F(lo) != x) lo = hi;
    return lo;
}

int main(){

    ll x;

    while(scanf("%llu", &x) == 1)
        printf("%llu\n", solve(x));

    return 0;
}
