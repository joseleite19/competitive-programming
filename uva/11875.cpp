#include <bits/stdc++.h>

using namespace std;

int n, v[200];

int main(){

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; tc++){
        scanf("%d", &n);

        for(int i = 0; i < n; i++) scanf("%d", v+i);

        printf("Case %d: %d\n", tc, v[n / 2]);
    
    }

}
