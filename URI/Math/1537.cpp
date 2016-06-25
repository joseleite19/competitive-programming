#include <cstdio>

int main(){
    int n;
    long long int f;

    while(scanf("%d", &n), n){
        f = 1;
        while(n>3){
            f = (f*n)%1000000009;
            n--;
        }
        printf("%lld\n", f);
    }
    return 0;
}