#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;

int n, a, b, c;

int p[111], vis[111], L[111];

void dfs(int u){
    for(int v : g[u]) if(v != p[u]){
        p[v] = u;
        L[v] = L[u]+1;
        dfs(v);
    }
}

int lca(int u, int v){
    
    while(u != v){
        if(L[u] > L[v]) u = p[u];
        else v = p[v];
    }

    return u;
}

double serie(double x){
    return x / (1 - x);
}

int main(){

    while(scanf("%d %d %d %d", &n, &a, &b, &c) == 4){
        g.assign(n+1, vector<int>());
        for(int i = 1; i < n; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        L[a] = 1;
        p[a] = -1;
        dfs(a);
        int l = lca(b, c);
        if(l == b){ printf("1.000000\n"); continue; }
        if(l == c){ printf("0.000000\n"); continue; }
        int q = L[b] - L[l];
        int w = L[c] - L[l];

        //printf("%d %d %lf\n", q, w, 1.0/(1<<(abs(q-w)+1)));

        double ans;
        if(q == w) ans = 0.5;
        else ans = serie(1.0/(1<<(abs(q - w)+1)));
        if(q < w) ans;
        else if(q > w) ans = 1-ans;
        printf("%.6lf\n", ans);
        //printf("%.6lf\n", 1.0 * w / (q+w));
    }


    return 0;
}
