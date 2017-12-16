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
const int N = 2200006;

ll sum[N], cnt[N];
int v[N];
int mark[N];
int main(){

    int n;
    ll x, y;

    scanf("%d %lld %lld", &n, &x, &y);

    for(int i = 0; i < n; i++){
        scanf("%d", v+i);
        cnt[ v[i]+1 ]++;
        mark[ v[i] ]++;
    }

    for(int i = 1; i < N; i++)
        cnt[i] += cnt[i-1];

    for(int i = 1; i < N; i++)
        sum[i] = sum[i-1] + cnt[i];
    
    ll ans = oo;
    int k = x / y;
    for(int i = 2; i < N; i++){ //i is the gcd
        int qnt = 0;
        int len = k;
        if(len >= i) len = i-1;
        ll cost = 0;
        //printf("%d\n", len);
        for(int j = i; j < N; j += i){
            //[j - len + 1, j]
            cost += (sum[j] - sum[j - len] - len*cnt[j-len])*y;
            qnt += mark[j];
            qnt += cnt[j] - cnt[j - len];
            //printf("%d %lld %lld\n", j, sum[j-len] + len*cnt[j-len] + len*mark[j-len], sum[j]);
        }
        cost += 1LL*(n - qnt)*x;
        //printf("%d %lld\n", i, cost);
        ans = min(ans, cost);
    }

    printf("%lld\n", ans);


    return 0;
}
