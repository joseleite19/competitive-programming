#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

long long sum[N];
long long cnt[N], tmp[N];

int n, k, q;

int main(){

    scanf("%d %d %d", &n, &k, &q);

    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        cnt[a]++, cnt[b+1]--;   
    }
    long long w = 0;
    for(int i = 0; i < N; i++){
        w += cnt[i];
        if(w >= k){
            sum[i] = 1;
        }
    }

    for(int i = 1; i < N; i++)
        sum[i] += sum[i-1];

    while(q--){
        int a, b;

        scanf("%d %d", &a, &b);
        printf("%lld\n", sum[b] - sum[a-1]);
    
    }
}
