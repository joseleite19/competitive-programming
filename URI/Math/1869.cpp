#include <cstdio>
 
char digito[32];
 
void base32(unsigned long long int n){
    if(n){
        base32(n / 32);
        printf("%c", digito[n % 32]);
    }
}
 
int main(){
    unsigned long long int n;
    for(n = 0; n < 10; n++) digito[n] = n + '0';
    for(; n < 32; n++) digito[n] = n - 10 + 'A';
 
    while(scanf(" %llu", &n) == 1 && n){
        base32(n);
        printf("\n");
    }
    printf("0\n");
 
    return 0;
}