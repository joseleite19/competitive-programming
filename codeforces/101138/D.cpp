#include <bits/stdc++.h>

using namespace std;

const int N = 50004;

int cnt[N];

int v[N];

int main(){

    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    int q;

    scanf("%d", &q);

    int a, b, c, d;
    int i, ans;
    while(q--){
        scanf("%d %d %d %d", &a, &b, &c, &d); a--, b--, c--, d--;
        for(i = a; i <= b; i++)
            cnt[ v[i] ]++;
        ans = 0;
        for(i = c; i <= d; i++)
            ans += cnt[ v[i] ];
        for(i = a; i <= b; i++) cnt[ v[i] ] = 0;
        printf("%d\n", ans);
    }


}
