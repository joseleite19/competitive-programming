#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

const int N = 10004;

const int oo= 1000000000;

vector<int> g[N];

int dp[N][111];
int n;

int c[N], v[N], s[N], e[N];

int cnt;
int dfs(int u, int pai){
    v[cnt] = u;
    s[u] = cnt++;
    for(int v : g[u]) if(v != pai)
        dfs(v, u);
    v[cnt] = u;
    e[u] = cnt++;
}

int f(int u, int x){
    if(x == 0) return 0;
    if(u >= cnt) return -oo;
    int &ans = dp[u][x];
    if(~ans) return ans;
    if(e[ v[u] ] == u) return ans = f(u+1, x);
    ans = f(u+1, x);
    if(f(e[ v[u] ]+1, x-1) != -oo)
        ans = max(ans, f(e[ v[u] ], x-1) + c[ v[u] ]);
    return ans;
}

int main(){

    memset(dp, -1, sizeof dp);
    int x;
    scanf("%d %d", &n, &x);

    for(int i = 1; i <= n; i++)
        scanf("%d", c+i);

    for(int i = 1; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 1);

    int ans = f(0, x);

    if(ans == -oo) printf("impossivel\n");
    else printf("%d\n", ans);
}

