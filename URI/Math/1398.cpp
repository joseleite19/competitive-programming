#include <cstdio>
#include <cstring>

#define MOD 131071

long long int exponencia(long long int base, long long int exp){
    int ans = 1;

    while(exp){
        if(exp & 1) ans = ((long long) ans * base) % MOD;
        base = ((long long)base * base) % MOD;
        exp >>= 1;
    }

    return ans;
}

int main(){
    long long int a;
    int i, j, n;

    char bin[11000], aux[11000];
     
    while(scanf(" %[^\n]",bin) == 1){
        while(bin[strlen(bin)-1] != '#'){
            scanf(" %[^\n]",aux);
            strcat(bin, aux);
        }
        a = 0;
        n = strlen(bin) - 2;
        for(i = 0; i <= n; i++)
            if(bin[i] == '1')
                a += exponencia(2, n-i);

        printf("%s\n", (a % MOD == 0 ? "YES" : "NO"));
    }
  
    return 0;
}