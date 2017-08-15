#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

const int N = 100005;

int n, q;

vector<int> g[N];
int p[N], L[N];
int dp[N][20];

void dfs_cnt(int u){    
    for(int v : g[u]){
        L[v] = L[u] + 1;
        dfs_cnt(v);
    }
}

int f(int u, int lvl){
    int &ans = dp[u][lvl];

    if(~ans) return ans;

    if(lvl == 0) return ans = p[u];

    return ans = f(f(u, lvl-1), lvl-1);
}

int LCA(int u, int v){
    if(L[u] < L[v]) swap(u, v);

    for(int lg = 20; lg >= 0; lg--){
        if(L[u] - (1 << lg) >= L[v]){
            u = f(u, lg);
        }
    }

    if(u == v) return u;

    for(int lg = 20; lg >= 0; lg--){
        if((1 << lg) <= L[u] && f(u, lg) != f(v, lg))
            u = f(u, lg), v = f(v, lg);
    }
    return p[u];
}

int dist(int a, int b){
    return L[a] + L[b] - 2*L[ LCA(a, b) ];
}

int solve(int s, int t, int f){
    if(L[s] < L[f]) swap(s, f);
    if(L[t] < L[f]) swap(t, f);
    
    if(f == s || f == t) return 1+dist(s, t);
    else if(s == t) return 1+dist(s, f);
    
    int q = LCA(s, t);

    if(q == f){
        return 1+max(L[s] - L[q], L[t] - L[q]);
    }

    if(dist(f, q) == abs(L[f] - L[q])){
        if(L[q] >= L[f])
            return 1+max(max(L[s] - L[q], L[t] - L[q]), dist(f, q));
        if(dist(f, s) == L[s] - L[f]
        || dist(f, t) == L[t] - L[f])
            return 1+max(dist(f, s), dist(f, t));
       int e = LCA(s, f);
       int w = LCA(t, f);
       return 1+(max(max(dist(w, s), dist(w, t)), dist(w, f)),
               max(max(dist(e, s), dist(e, t)), dist(e, f)));
    }

    return 1+max(max(dist(q, s), dist(q, t)), dist(f, q));
}

int main(){

    scanf("%d %d", &n, &q);

    for(int i = 2; i <= n; i++){
        scanf("%d", p+i);
        g[ p[i] ].push_back(i);
    }

    dfs_cnt(1);
    memset(dp, -1, sizeof dp);

    int a, b, c;
    while(q--){
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", solve(a, b, c));
    }

    return 0;
}
