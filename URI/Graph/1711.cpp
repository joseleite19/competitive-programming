#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;


int p[N];
int pw[N];
int sz[N];
int vis[N], dist[N];

vector<vector<pair<int, int>>> g;

int back(int s, int t, int w){
    if(s == t) return sz[s] = w;
    return sz[s] = back(p[s], t, w + pw[s]);
}

void dfs(int u){
    
    vis[u] = 1;
    for(auto x : g[u]){
        int v, w;
        tie(v, w) = x;
        if(v == p[u]) continue;

        if(!vis[v]){
            p[v] = u;
            pw[v] = w;
            dfs(v);
        }
        else if(vis[v] == 1){
            back(u, v, w);
        }

    }
    vis[u] = 2;
}

int pass, n;
int solve(int s, int tam){
    priority_queue<pair<int, int>> q;
    
    for(int i = 1; i <= n; i++) dist[i] = MOD;
    q.ep(0, s);
    dist[s] = 0;

    int u, w, v;
    int ans = MOD;
    while(!q.empty()){
        tie(w, u) = q.top(); q.pop(); w = -w;
        if(w > dist[u]) continue;
        if(sz[u] >= tam) ans = min(ans, sz[u] + dist[u]);

        for(auto x : g[u]){
            tie(v, w) = x;
            if(dist[v] > dist[u] + 2*w){
                dist[v] = dist[u] + 2*w;
                q.ep(-dist[v], v);
            }
        }
    }

    if(ans != MOD) return ans;

    return -1;
}

int main(){

    int m;
    while(scanf("%d %d", &n, &m) == 2){
        pass = 3;
        g.assign(n+1, vector<pair<int, int>>());

        for(int i = 0; i < m; i++){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            g[a].eb(b, c);
            g[b].eb(a, c);
        }

        memset(p, 0, sizeof p);
        memset(pw, 0, sizeof pw);
        memset(vis, 0, sizeof vis);
        memset(sz, 0, sizeof sz);

        for(int i = 1; i <= n; i++) if(!vis[i])
            dfs(i);

        int q;

        scanf("%d", &q);
        int u, tam;
        while(q--){
            scanf("%d %d", &u, &tam);

            printf("%d\n", solve(u, tam));
        }
    }



    return 0;
}
