#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, k;

long long sum[N], v[N];

long long f(int mid, int i){
    return (i - mid) * v[i] - (sum[i-1] - sum[mid-1]);
}

int main(){

    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++)
        scanf("%lld", v+i);

    sort(v+1, v+n+1);

    for(int i = 1; i <= n; i++)
        sum[i] = sum[i-1] + v[i];

    int mx = -1, nb = -1;
    for(int i = 1; i <= n; i++){
        int lo = 1, hi = i;
        
        while(lo + 1 < hi){
            int mid = (lo+hi)/2;
            if(f(mid, i) <= k) hi = mid;
            else lo = mid+1; 
        }
        if(f(lo, i) > k) lo = hi;
        
        if(i - lo+1 > mx){
            mx = i - lo + 1;
            nb = v[i];
        }
    }

    printf("%d %d\n", mx, nb);

    return 0;
}
