#include <bits/stdc++.h>

using namespace std;

int v[2222];

int main(){

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    long long sum = 0;
    for(int i = 0; i < n; i++)
        sum += v[i];

    int m;

    scanf("%d", &m);

    int ans = -1;

    for(int i = 1; i <= m; i++){
        int l, r;
        scanf("%d %d", &l, &r);
        if(sum <= r){ ans = max(1LL*l, sum); break; }
    }
    printf("%d\n", ans);


    return 0;
}
