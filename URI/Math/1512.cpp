#include <cstdio>

long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    long long n, a, b;

    while(scanf(" %lld %lld %lld", &n, &a, &b), n + a + b)
        printf("%lld\n",n/a + n/b - n*gcd(a,b)/a/b);
}