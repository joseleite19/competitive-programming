#include <cstdio>

int main(){
    int fat[] = {1,2,6,24,120};
    
    int n, total, a;
    while(scanf(" %d",&n), n){
        total = 0;
        for(int i = 0; n; i++){
            total += (n%10) * fat[i];
            n /= 10;
        }
        printf("%d\n", total);
    }
}