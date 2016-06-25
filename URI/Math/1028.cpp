#include <stdio.h>
int menor(int a,int b){
    return a < b ? a : b;
}

int maior(int a, int b){
    return a > b ? a : b;
}

int main(){
    int a, b, c, i, d, e;

    for(scanf("%d",&a); a>0 ;a--){
        scanf("%d %d",&b,&c);

        i = menor(c,b);
        d = maior(c,b);
        while(d%i!=0){
            e = i;
            i = d%i;
            d = e;
        }

        printf("%d\n",i);
    }

    return 0;
}
