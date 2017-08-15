#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

long long cnt[N];


int main(){

    int n, m;

    scanf("%d %d", &n, &m);

    long long all = 0;

    long long last = 0;
    for(int i = 0; i < n; i++){
        long long x;
        scanf("%lld", &x);
        x -= last;
        cnt[i % m] += x;
        all += x;

        last += x;
    }

    for(int i = 0; i < m; i++)
        printf("%lld ", all - cnt[i]);
    printf("\n");

}
