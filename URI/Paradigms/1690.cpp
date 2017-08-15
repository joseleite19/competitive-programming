#include <bits/stdc++.h>

using namespace std;

int n;
long long v[10004];

int main(){

    int t;

    scanf("%d", &t);

    for(int tc = 1; tc <= t; tc++){
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
            scanf("%lld", v+i);
        sort(v, v+n);
        long long sum = 0;
        for(int i = 0; i < n; i++){
            if(v[i] > sum+1) break;
            sum += v[i];
        }
        printf("%lld\n", sum+1);
    }

}
