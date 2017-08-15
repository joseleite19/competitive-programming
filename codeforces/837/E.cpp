#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

const long long MAX = 1e18;


int main(){

    long long a, b;

    scanf("%lld %lld", &a, &b);

    map<long long, int> fat;

    long long n = a;
    for(long long i = 2; i*i <= a; i++){
        while(a % i == 0){
            fat[i]++, a /= i;
        }
    }
    if(a > 1) fat[a]++, a /= a;

    long long ans = 0;

    while(b){
        long long g = __gcd(n, b);
        n /= g, b /= g;
        if(n == 1){ ans += b; break; }
        
        for(pair<const long long, int> &x : fat) if(x.ss){
            while(g % x.ff == 0) x.ss--, g /= x.ff;
        }

        long long mn = MAX, fac = MAX, tmp;
        for(pair<const long long, int> &x : fat) if(x.ss){
            tmp = b % x.ff;
            if(tmp < mn) mn = tmp, fac = x.ff;
        }
        ans += mn;
        b -= mn;
    }

    printf("%lld\n", ans);



    return 0;
}
