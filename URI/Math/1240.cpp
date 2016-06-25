#include <cstdio>

int main(){
    unsigned long long int a, b, c, d, e;
    int n, i, j;

    scanf("%d",&n);
    while(n--){
        e = 10;
        scanf("%lld %lld", &a, &b);
        c = b;
        for(i = 0; c; i++)
            c /= 10;
        for(j = 1; j < i; j++)
            e *= 10;

        d = a / e;
        a -= d * e;
        if(a == b) printf("encaixa\n");
        else printf("nao encaixa\n");
    }

    return 0;
}
