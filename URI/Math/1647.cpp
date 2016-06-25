#include <cstdio>

int main(){
    int n, i, m[55];
    long long a;
    
    while(scanf("%d", &n), n){
        for(i = 0; i < n; i++)
            scanf(" %d",m+i);
        
        a = 0;
        for(i = n-1; i >= 0; i--)
            a = 2*a + m[i];
        
        printf("%lld\n", a);
    }
    
    return 0;
}