#include <stdio.h>
#include <math.h>

int main(){
    unsigned long long int grao;
    int n, i, x[101];
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", x + i);

    for(i=0;i<n;i++){
        grao = (unsigned long long int) pow(2, x[i])-1;
        grao = grao / 12000;
        printf("%lld kg\n", grao);
    }

    return 0;
}
