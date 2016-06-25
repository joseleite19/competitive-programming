#include <cstdio>

int main(){
    int n, r, a;

    for(int t = 1; scanf("%d %d", &r, &n), r, n; t++){
        a = r / n;
        if(r % n == 0) a--;
        printf("Case %d: ", t);
        if(a > 26) printf("impossible\n");
        else printf("%d\n", a);
    }

    return 0;
}