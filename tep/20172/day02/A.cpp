#include <bits/stdc++.h>

using namespace std;

long long ans[10000], p, x, y;



int main(){

    while(scanf("%lld %lld", &x, &y) == 2){
        
        for(p = 0; x > 0 && y > 0; p++){
            ans[p] = x / y;
            x %= y;
            swap(x, y);
        }

        printf("[%lld;%lld", ans[0], ans[1]);

        for(int i = 2; i < p; i++)
            printf(",%lld", ans[i]);

        printf("]\n");

    }


}
