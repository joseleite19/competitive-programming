#include <bits/stdc++.h>

using namespace std;

int n, m;
int tot = 0, ans = 0;

int v[10];

void back(int i, int mx){
    if(i == n){
        v[mx]++;
        ans += mx, tot++;    
        return;
    }
    for(int x = 1; x <= m; x++)
        back(i+1, max(mx, x));
}

int main(){

    m = 6, n = 3;

    back(0, 0);

    printf("%lf %d\n", 1.0*ans/tot, tot);

    for(int i = 1; i <= m; i++)
        printf("%d %d\n", i, v[i]);

    return 0;
}
