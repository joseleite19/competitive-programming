#include <cstdio>
#include <cmath>

int main(){
	unsigned long long int n;
    int t;
    scanf("%d", &t);
    while(t--){
        scanf(" %llu", &n);
        printf("%llu\n", (unsigned long long int)(-1 + sqrt(1 + 8*n)) / 2);
    }
    return 0;
}