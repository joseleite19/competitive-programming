#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
int mark[100005];

int phi(int n){
    int ans = n;;
    for(int i = 0; primes[i] * primes[i] <= n; i++){
        if(n % primes[i] == 0){
            ans = ans / primes[i] * (primes[i]-1);
            while(n % primes[i] == 0) n /= primes[i];
        }
    }
    if(n > 1) ans = ans / n * (n-1);
    return ans;
}

int f(long long b, int e, int mod){
    long long ans = 1;
    while(e){
        if(e &1) ans = (ans * b) % mod;
        b = (b * b) % mod;
        e >>= 1;
    }
    return (int) ans;
}

int solve(int n, int m){
    if(m == 1) return 0;
    return f(n, solve(n-1, phi(m)), m);
}


int main(){

    for(int i = 2; i < 100005; i++) if(!mark[i]){
        primes.push_back(i);
        for(int j = i; j < 100005; j += i)
            mark[j] = 1;
    }

    int n, m;

    scanf("%d %d", &n, &m);

    printf("%d\n", solve(n, m));



    return 0;
}
