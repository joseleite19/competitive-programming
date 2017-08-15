#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m;
long long v[N];

bool f(long long mid){
    
    int j = 0;
    while(j < n && !v[j]) j++;
    long long val = v[j];
    for(int i = 1; i <= m; i++){
        long long tmp = j+1;
        while(j < n && tmp < mid){
            if(mid >= tmp + val){
                tmp += val;
                j++;
                tmp++;
                while(j < n && !v[j]) j++, tmp++;
                val = v[j];
                if(tmp > mid) break;
            }
            else{
                val -= mid - tmp;
                break;
            }
        }

        if(j == n) break;
    }

    return j == n;
}

int main(){


    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    long long lo = 0, hi = 1e18;

    while(lo + 1 < hi){
        long long mid = (lo+hi)/2;
        if(f(mid)) hi = mid;
        else lo = mid+1;
    }
    if(!f(lo)) lo = hi;

    printf("%lld\n", lo);


    return 0;
}
