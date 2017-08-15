#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

const int N = 1000006;

int used[N], d[N], lp[N], pot[N];

long long pow(long long b, long long e){
    long long ans = 1;
    while(e){
        if(e & 1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ans;
}

long long f(int x){
    if(x == 0) return 0;
    long long ans = x;
    x--;
    long long b = 2;
    while(x){
        if(x & 1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        x >>= 1;
    }
    ans = (ans + MOD) % MOD;
    return ans;
}

int main(){

    for(int i = 2; i < N; i++){
        if(!lp[i]){
            lp[i] = i;
            pot[i] = 1;
            for(int j = i + i; j < N; j += i) if(!lp[j]){
                lp[j] = i;
            }
        }
        else{
            int j = i, is = 1;
            while(j > 1 && is){
                if(lp[j] != lp[i]) is = false;
                j /= lp[j];
            }
            if(is) pot[i] = 1;
        }
    }

    printf("%lld\n", f(3));

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        used[x]++;
    }

    long long ans = 0;
    for(int i = 2; i < N; i++) if(pot[i]){
        int qnt = 0;
        for(int j = i; j < N; j += i){
            qnt += used[j];
        }
        ans = (ans + 1LL*f(qnt)*lp[i]) % MOD;
        if(qnt) printf("%d %lld\n", i, f(qnt) * lp[i]);
    }

    printf("%lld\n", ans);



    return 0;
}
