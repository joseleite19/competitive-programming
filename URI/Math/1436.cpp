#include <cstdio>

int main(){
    int n, t;
    
    scanf("%d",&t);
    for(int j = 0; j < t; j++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &k);
            if(i == n/2)
                printf("Case %d: %d\n", j+1, k);
        }
    }

    return 0;
}
