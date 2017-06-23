#include <bits/stdc++.h>

#define ff first
#define ss second

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
const int N = 100005;
int n;
long long v[N], x;

int main(){

    scanf("%d %lld", &n, &x);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    long long zero = MOD, cnt = 0, sum = 0;

    map<long long, int> s;
    for(int i = 0; i < n; i++){
        sum += v[i];
    }
    for(int i = 0; i < n; i++){
        s[sum - v[i]]++;
        zero = min(zero, sum - v[i]);
    }

    long long ans = zero;

    while(1){
        zero = (*s.begin()).ff;
        cnt = (*s.begin()).ss;
        if(cnt % x == 0){
            s.erase(s.begin());
            s[zero+1] += cnt / x;
        }
        else{
            ans = zero;
            break;
        }
    }

    ans = min(ans, sum);

    printf("%lld\n", f(x, ans));




    return 0;
}
