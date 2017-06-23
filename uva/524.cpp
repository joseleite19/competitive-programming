#include <bits/stdc++.h>

using namespace std;

int n;
int used[20], ans[20];

bool prime[20];

void f(int i){
    if(i == n){
        if(!prime[ans[n-1] + 1]) return;
        printf("%d", ans[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", ans[i]);
        printf("\n");
        return;
    }
    for(int j = 1; j <= n; j++) if(!used[j]){
        if(prime[ ans[i-1] + j]){
            used[j] = 1;
            ans[i] = j;
            f(i+1);
            used[j] = 0;
        }
    }
}


int main(){

    prime[2] = prime[3] = prime[5] = prime[7] = prime[11] = prime[13] = prime[17] = prime[19] = prime[23] = prime[29] = prime[31] = 1;

    for(int tc = 1; scanf("%d", &n) == 1; tc++){
        if(tc > 1) printf("\n");
        printf("Case %d:\n", tc);
        used[1] = 1; ans[0] = 1;
        f(1);
    }



    return 0;
}
