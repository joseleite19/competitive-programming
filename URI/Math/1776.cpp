#include <cstdio>
#include <cmath>

int main(){
    int primos[31700], i, s, t = 0, c, b, r, a, n, p[3409];
    
    for(i = 2; i < 31700; i++)
        primos[i] = 1;

    for(i = 2; i < 31700; i++){
        if(primos[i]){
            p[t++] = primos[i];
            n = i*i;
            while(n < 31700){
                primos[n] = 0;
                n += i;
            }
        }
    }

    scanf("%d", &t);
    for(s = 1; s <= t; s++){
        a = 1;
        scanf("%d", &n);
        b = n;
        r = sqrt(n);
        for(i = 0; p[i] <= r && n > 1; i++){
            c = 0;
            while(n % p[i] == 0){
                n /= p[i];
                c++;
            }
            if(c & 1)
                a *= p[i];
        }

        a *= n;
        printf("Caso #%d: %lld\n", s, (long long int)a * b);
    }
}