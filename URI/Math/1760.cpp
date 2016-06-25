#include <cstdio>
#include <cmath>

int main(){
    int t;

    while(scanf(" %d",&t) == 1)
        printf("%.2lf\n", t * t * sqrt(3) * 2 / 5);
}