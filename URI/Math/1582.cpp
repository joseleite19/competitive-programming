#include <cstdio>
#include <cmath>
  
int mdc(int a, int b){
    return b ? mdc(b, a % b) : a;
}
  
int main(){
    int x, y, z;

    while(scanf(" %d %d %d", &x, &y, &z) == 3){
        printf("tripla");

        if((x*x) == (y*y + z*z) || (y*y) == (x*x + z*z) || (z*z) == (y*y + x*x)){
            printf(" pitagorica");
            if(mdc(mdc(x, y), z) == 1) printf(" primitiva");
        }
        printf("\n");
    }
    return 0;
}