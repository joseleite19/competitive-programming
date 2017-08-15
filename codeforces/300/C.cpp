#include <bits/stdc++.h>

#define MOD 1000000007LL

using namespace std;

const int N = 1000006;

long long a, b, n, fat[N];

bool good(long long x){
    while(x){
        if(x % 10 != a && x % 10 != b) return false;
        x /= 10;
    }
    return true;
}

long long f(long long b, long long e){
    long long ans = 1;
    while(e){
        if(e & 1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ans;
}

long long mult(long long a, long long b){
    return (a * b) % MOD;
}

long long sum(long long a, long long b){
    long long ans = a + b;
    if(ans > MOD) ans -= MOD;
    return ans;
}

int main(){
    fat[0] = 1;
    for(int i = 1; i < N; i++)
        fat[i] = mult(fat[i-1], i);

    scanf("%lld %lld %lld", &a, &b, &n);

    long long ans = 0;
    for(int i = 0; i <= n; i++){
        if(good(i*a + (n-i)*b)){
            ans = sum(ans, mult(mult(fat[n], f(fat[i], MOD-2)), f(fat[n-i], MOD-2)));
        }
    }

    printf("%lld\n", ans);


    return 0;
}
