#include <bits/stdc++.h>

#define MOD (1000000007)

using namespace std;

const int N = 1003;

int n, p[N];

long long dist[N], f[N];

int main(){

    memset(dist, -1, sizeof dist);
    memset(f, -1, sizeof f);

    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d", p+i);

    long long ptr = 1;
    long long cnt = 0;

    while(ptr != n+1){
        if(f[ptr] == -1){
            f[ptr] = cnt;
            cnt++;
            ptr = p[ptr];
        }
        else if(dist[ptr] == -1){
            dist[ptr] = (cnt - f[ptr] + MOD) % MOD;
            cnt++;
            ptr++;
        }
        else{
            cnt += 1+dist[ptr];
            ptr++;
        }
        cnt %= MOD;
    }

    printf("%lld\n", cnt);



    return 0;
}
