#include <stdio.h>

int main(){
    unsigned long long int prod[21];
    int i, a, b;
    prod[0] = 1;
    for(i = 1; i < 21; i++)
        prod[i] = i * prod[i-1];

    while(scanf("%d %d",&a,&b) == 2)
        printf("%lld\n", prod[a] + prod[b]);

    return 0;
}
