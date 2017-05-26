#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD (1000000007)

using namespace std;

long long f(long long b, long long e){
    long long ans = 1;

    while(e){
        if(e & 1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ans;
}

int n;
long long v[300005];

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    sort(v, v+n);

    if(n <= 1) return printf("0\n"), 0;

    long long sum = 0;
    for(int j = 1; j < n; j++){
        sum = (sum + ((v[j]*f(2, j-1))%MOD)) % MOD;
    }

    long long ans = 0;

    for(int i = 0; i+1 < n; i++){
        long long tmp = (v[i]*(f(2, n-i-1)-1+MOD))%MOD;
        ans += (sum - tmp + MOD) % MOD;
        ans %= MOD;
    //printf("%lld %lld %lld %d\n", ans, sum, tmp, n-i-1);
        sum = (MOD + sum - ((v[i+1]*f(2, 0))%MOD)) % MOD;
        //printf("%lld\n", sum);
        sum = (sum * f(2, MOD-2)) % MOD;
    }

    printf("%lld\n", ans);









	return 0;
}
