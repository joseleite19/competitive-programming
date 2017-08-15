#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

long long h, v[N];
int n;

bool f(long long mid){
    long long tmp = mid % n;
    long long qnt = mid / n;
    long long tot = 0;
    for(int i = 0; i < n; i++){
        tot += qnt * v[i];
        if(tmp) tot += v[i], tmp--;
    }
    tot += mid * (mid+1) / 2;
    return tot >= h;
}

int main(){

    scanf("%d %lld", &n, &h);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    long long now = 0;
    int day = 0;

    for(int day = 0; day < 4*n; day++){
        if(now >= h) return printf("%d\n", day), 0;
        now += v[day % n] + day+1;
    }

    long long hi = 1LL << 31, lo = 0;

    while(lo + 1 < hi){
        long long mid = (lo + hi) / 2;
        if(f(mid)) hi = mid;
        else lo = mid+1;
    }
    if(!f(lo)) lo = hi;

    printf("%lld\n", lo);


    return 0;
}
