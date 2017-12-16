#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

const int N = 1000006;

int used[N], lp[N], pot[N];

long long tmp[N];

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

vector<int> d[N];

int main(){

    for(int i = 2; i < N; i++){
        for(int j = i+i; j < N; j += i)
            d[j].push_back(i);
    }

    for(int i = 2; i < N; i++){
        if(!lp[i]){
            lp[i] = i;
            for(int j = i + i; j < N; j += i) if(!lp[j]){
                lp[j] = i;
            }
        }
    }


    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        used[x]++;
    }

    long long ans = 0;
    for(int i = 2; i < N; i++){
        int qnt = 0;
        for(int j = i; j < N; j += i){
            qnt += used[j];
        }
        tmp[i] = (1LL*f(qnt)*i) % MOD;
        ans = (ans + tmp[i]) % MOD;
        for(int x : d[i]) if(x != i){
            ans = (ans - tmp[x] + MOD) % MOD;
        }
        //if(qnt) printf("%d %lld\n", i, f(qnt) * lp[i]);
    }

    for(int i = 2; i < 10; i++)
        printf("%d %lld\n", i, tmp[i]);

    printf("%lld\n", ans);



    return 0;
}
