#include <bits/stdc++.h>

using namespace std;

const int N = 2666;

vector<int> g[N];
int p[N], num[N], low[N];
int cnt = 1;

set<int> vv[N];

void dfs(int u){
    low[u] = num[u] = cnt++; // dfs_low[u] <= dfs_num[u]
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(num[v] == 0){
            p[v] = u;
            dfs(v);
            if(low[v] > num[u]) // for bridge
                vv[u].insert(v), vv[v].insert(u)/*.push_back({u, v})*/;
            low[u] = min(low[u], low[v]); // update dfs_low[u]
        }
        else if(v != p[u]) // a back edge and not direct cycle
            low[u] = min(low[u], num[v]); // update dfs_low[u]
    }
}


int dfs2(int u){
    int ret = 1;
    num[u] = 1;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(!num[v] && !vv[u].count(v)){
            ret += dfs2(v);
        }
    }
    return ret;
}

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(!num[i]){
            dfs(i);
        }
    }

    memset(num, 0, sizeof num);

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!num[i]){
            if(dfs2(i) % 2 == 0) ans = 1;
        }
    }

    printf("%s\n", ans ? "IMPAR" : "PAR");
    


}
