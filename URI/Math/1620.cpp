#include <cstdio>

int main(){
    double l;
    
    while(scanf("%lf", &l) == 1, l)
        printf("%.6lf\n", (l-3) / l);

    return 0;
}