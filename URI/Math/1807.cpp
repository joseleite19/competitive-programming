#include <stdio.h>

#define MOD 2147483647

long long exponencia(long long int base, int exp){
    if(exp == 0) return 1;
    if(exp & 1) return (base*(exponencia((base * base) % MOD,exp/2))) % MOD;
    return exponencia((base * base) % MOD, exp/2) % MOD;
}
int main(){
    int n;

    scanf("%d",&n);
    printf("%lld\n",exponencia(3,n));
    
    return 0;
}