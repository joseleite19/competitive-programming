#include <cstdio>
#include <cmath>

int main(){
    int t;
    bool prime;
    long long int c, n, i;

    scanf("%d", &t);
    while(t--){
        prime = true;
        scanf("%lld", &n);
        if(n == 2) printf("Prime\n");
        else{
            c = sqrt(n);
            for(i = 3; i < c; i += 2){
                if(n % i == 0){
                    prime = false;
                    break;
                }
            }
            if(prime) printf("Prime\n");
            else printf("Not Prime\n");
        }
    }

    return 0;
}
