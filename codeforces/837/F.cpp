#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

const int N = 200005;

long long v[N], k;
int n;

inline int LG(long long x){
    return 63 - __builtin_clzll(x);
}

bool f(int mid){
    mid--;
    long long ans = v[2];

    ans += v[1] * (mid+1);
    if(ans >= k) return 1;

    long long tmp = 1LL * (mid+2)*(mid+1)/2;
    if(tmp >= k) return 1;

    if(LG(tmp) + LG(v[0]) > 60) return 1;
    
    if(tmp * v[0] >= k) return 1;

    ans += tmp * v[0];

    if(ans >= k) return 1;

    return 0;
}

int main(){

    scanf("%d %lld", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    for(int i = 0; i < n; i++) if(v[i] >= k)
        return printf("0\n"), 0;
    {
        int j = 0;
        for(j = 0; j < n; j++) if(v[j])
            break;
        
        for(int i = 0; i < n - j; i++)
            v[i] = v[j+i];
            
        n -= j;
    }

    if(n == 2)
        return printf("%lld\n", (k - v[1] + v[0] - 1) / v[0]), 0;

    for(int i = 1; i < n; i++)
        v[i] += v[i-1];

    if(n == 3){

        long long lo = 0, hi = 2e9;

        while(lo + 1 < hi){
            long long mid = (lo + hi) / 2;
            if(f(mid)) hi = mid;
            else lo = mid+1;
        }
        if(!f(lo)) lo = hi;
        printf("%lld\n", lo+1);

        return 0;
    }

    int ans = 1;

    bool keep = true;
    while(keep){
        ans++;
        for(int i = 1; i < n; i++){
            v[i] += v[i-1];
            if(v[i] >= k){
                keep = false;
                break;
            }
        }
    }

    printf("%d\n", ans);


    return 0;
}
