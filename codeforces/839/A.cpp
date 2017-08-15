#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k;

    int sum = 0;

    scanf("%d %d", &n, &k);
    
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        sum += x;
        int tmp = min(8, sum);
        k -= tmp;
        sum -= tmp;
        if(k <= 0) return printf("%d\n", i+1), 0;
    }

    printf("-1\n");


    return 0;
}
