#include <cstdio>
#include <cmath>

int main(){
    int n, R, r;
    
    scanf("%d %d %d", &n, &R, &r);

    printf("%.10lf\n", sin(acos(-1)/n)*n*R*r);
    
    return 0;
}