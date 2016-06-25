#include <cstdio>
#include <cstdlib>

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    int n, a, b;
    char s1[35], s2[35];

    scanf("%d",&n);
    for(int t = 0; t < n; t++){
        scanf(" %s %s", s1, s2);
        a = strtol(s1, NULL, 2);
        b = strtol(s2, NULL, 2);

        printf("Pair #%d: ", t + 1);
        if(gcd(a, b) > 1) printf("All you need is love!\n");
        else printf("Love is not all you need!\n");
    }
    return 0;
}
