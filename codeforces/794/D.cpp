#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

vector<int> g[300005];
set<int> h[300005];
int n, m, color[300005], ans[300005];
int vis[300005];
bool loop = false;
int ptr = 1;
void dfs(int u, int p, int pt, int add){
    ans[u] = pt;
    vis[u] = 1;
    for(int v : h[u]){
        if(v == p) continue;
        if(vis[v]) loop = true;
        else if(add == 0){
            dfs(v, u, pt+1, 1);
            add = -1;
        }
        else{
            dfs(v, u, pt+add, add);
        }
    }
}

int main(){

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) g[i].push_back(i);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v); u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i < n; i++) sort(g[i].begin(), g[i].end());

    map<vector<int>, vector<int> > mm;
    for(int i = 0; i < n; i++) mm[ g[i] ].push_back(i);

    ptr = 1;
    for(map<vector<int>, vector<int> >::iterator it = mm.begin(); it != mm.end(); it++){
        vector<int> &tmp = it->ss;
        for(size_t i = 0; i < tmp.size(); i++)
            color[ tmp[i] ] = ptr;
        ptr++;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < g[i].size(); j++){
            int v = g[i][j];
            if(color[i] == color[v]) continue;
            h[ color[i] ].insert(color[v]);
            h[ color[v] ].insert(color[i]);
        }
    }

    for(int i = 0; i < n; i++) if(h[i].size() >= 3) return printf("NO\n"), 0;

    for(int i = 0; i < n; i++){
        if(!vis[ color[i] ])
            dfs(color[i] , -1, 1, 0);
    }

    if(loop) return printf("NO\n"), 0;

    int mn = 1000000000;
    for(int i = 0; i < n; i++)
        mn = min(mn, ans[ color[i] ]);
    if(mn > 0) mn = 0;
    else mn = -mn + 1;
    printf("YES\n");
    for(int i = 0; i < n; i++)
        printf("%d ", ans[ color[i] ] + mn);
    printf("\n");






    return 0;
}
