#include <bits/stdc++.h>

using namespace std;

const int N = 5003;

int n, m, v[N], mark[N];

int q[N], w[N], to[N], p[N];

int dp[N][2*N];

int f(int i, int last){
    if(i == n) return last;

    if(~dp[i][last]) return dp[i][last];

    int ans = last + f(i+1, 0);

    if(to[i] != -1)
        ans = max(ans, max(last + f(to[i]+1, p[i]), f(to[i]+1, last^p[i])));

    return dp[i][last] = ans;
}

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    memset(to, -1, sizeof to);
    memset(q, -1, sizeof q);
    memset(w, -1, sizeof w);
    memset(dp, -1, sizeof dp);

    for(int i = 0; i < n; i++)
        if(q[ v[i] ] == -1)
            q[ v[i] ] = i;

    for(int i = n-1; i >= 0; i--)
        if(w[ v[i] ] == -1)
            w[ v[i] ] = i;

    for(int i = 0; i < n; i++){
        if(q[ v[i] ] != i) continue;
        int r = w[ v[i] ];
        int x = 0;
        bool can = true;
        for(int j = i; j <= r; j++){
            if(q[ v[j] ] < i) can = false;
            if(!mark[ v[j] ]) x ^= v[j];
            mark[ v[j] ]++;
            r = max(r, w[ v[j] ]);
        }
        for(int j = i; j <= r; j++) mark[ v[j] ] = 0;
        if(!can) continue;
        to[i] = r;
        p[i] = x;
    }
    /*for(int i = 0; i < n; i++)
        printf("%d %d\n", to[i], p[i]);*/

    printf("%d\n", f(0, 0));

    return 0;
}
