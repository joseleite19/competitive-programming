#include <cstdio>

int main(){
    int n, sum;

    while(scanf("%d", &n), n){
        sum = 0;
        for(int i = 1; i <= n; i++)
            sum += i * i;
        printf("%d\n", sum);
    }

    return 0;
}
