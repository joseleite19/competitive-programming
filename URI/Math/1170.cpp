#include <cstdio>

int main(){
    int i, n, a, b;
    double c;

    for(scanf("%d",&n); n > 0 ;n--){
        scanf("%lf", &c);
        for(i = 0; c > 1; i++)
            c /= 2;
        printf("%d dias\n",i);
    }
    return 0;
}