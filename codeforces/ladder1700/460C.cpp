#include <bits/stdc++.h>

using namespace std;

const int N = 1000006;

int v[N], n, w, m;
long long d[N];

bool f(int mid){
    memset(d, 0, sizeof d);

    long long x = 0;
    long long used = 0;
    for(int i = 0; i < n; i++){
        x += d[i];
        if(v[i] + x < mid){
            int tmp = mid - (v[i] + x);
            used += tmp;
            if(used > m) return 0;
            x += tmp;
            d[i+w] -= tmp;
        }
    }
    return 1;
}

int main(){

    scanf("%d %d %d", &n, &m, &w);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    long long lo = 1, hi = 1e15;

    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if(!f(mid)) hi = mid-1;
        else lo = mid;
    }

    if(!f(hi)) hi = lo;

    printf("%lld\n", hi);


    return 0;
}
