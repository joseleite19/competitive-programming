#include <cstdio>
#include <cmath>

int main(){
    int d, vf, vg;
    while(scanf(" %d %d %d",&d,&vf,&vg) == 3)
        printf("%c\n", 12.0/vf >= sqrt(144 + d*d)/vg ? 'S' : 'N');

    return 0;
}