#include <bits/stdc++.h>

#define MOD (1000000007)

using namespace std;

const int N = 202;
long long dp[N+100][N+100];

long long C(int n, int k){
    if(k > n) return 0;
    if(n == k || n == 0 || k == 0) return 1;
    if(~dp[n][k]) return dp[n][k];
    return dp[n][k] = (C(n-1, k) + C(n-1, k-1)) % MOD;
}

vector<int> g[N];

long long f(int u, int v){
    long long ans = 0;

    int rep = 0;
    {
        int i = 0, j = 0;
        while(i < g[u].size() && j < g[v].size()){
            if(g[u][i] < g[v][j]) i++;
            else if(g[u][i] > g[v][j]) j++;
            else rep++, i++, j++;
        }
    }

    int a = int(g[u].size()) - rep - 1, b = int(g[v].size()) - rep - 1;

    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 2; j++){
            if(j + i > rep) continue;
            long long tmp = (C(a, 3-i) * C(b, 2-j)) % MOD;
            tmp = (tmp * C(rep, i)) % MOD;
            tmp = (tmp * C(rep-i, j)) % MOD;
            ans += tmp;
        }
    }


    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);

    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());

    long long ans = 0;

    for(int u = 1; u <= n; u++){
        for(int v : g[u]){
            if(g[u].size() >= 4 && g[v].size() >= 3)
                ans = (ans + f(u, v)) % MOD;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
