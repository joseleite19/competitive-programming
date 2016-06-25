#include <cstdio>

int maior(int a, int b){
    return a > b ? a : b;
}

int main(){
    int t, b, c, r, m, x, y;

    scanf("%d",&t);
    while(t--){
        scanf("%d %d", &x, &y);
        r = 9*x*x + y*y;
        b = 2*x*x + 25*y*y;
        c = -100*x + y*y*y;
        
        m = maior(maior(r, b), c);
        
        if(r == m) printf("Rafael ganhou\n");
        else if(b == m) printf("Beto ganhou\n");
        else printf("Carlos ganhou\n");
    }

    return 0;
}
