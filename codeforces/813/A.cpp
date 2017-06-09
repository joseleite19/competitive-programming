#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, v[1003];

int main(){

    int sum = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i), sum += v[i];

    int m, l, r;
    scanf("%d", &m);

    int ans = -1;

    for(int i = 0; i < m; i++){
        scanf("%d %d", &l, &r);
        if(ans != -1) continue;
        if(l <= sum && sum <= r) ans = sum;
        if(l > sum) ans = l;
    }

    printf("%d\n", ans);






    return 0;
}
