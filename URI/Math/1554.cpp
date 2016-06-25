#include <cstdio>
#include <cmath>

double distancia(int a, int b, int c, int d){
    return sqrt((a-c)*(a-c) + (b-d)*(b-d));
}

int main(){
    int x, y, n, a, b, m, i, id, mula, t;

    scanf(" %d",&n);
    while(n--){
        scanf(" %d %d %d", &t, &a, &b);
        m = distancia(1420, 2840, a, b);
        
        id = 0;
        for(int i = 0; i < t; i++){
            scanf(" %d %d", &x, &y);
            mula=distancia(a, b, x, y);
            if(mula<m){
                m = mula;
                id = i+1;
            }
        }
        printf("%d\n", id);
    }
}