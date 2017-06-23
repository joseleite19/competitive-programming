#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 100005;

vector<pair<int, int> > query[N];

vector<int> g[N];

int c[N], ans[N], sz[N];

int dfs_cnt(int u, int p){
    sz[u] = 1;

    for(int v : g[u]) if(v != p)
        sz[u] += dfs_cnt(v, u);
    return sz[u];
}

map<int, int> cnt;
map<int, int> cnt2;
long long ft[N+1];

void update(int x, long long val){
    for(; x <= N; x += x&-x)
        ft[x] += val;
}

long long sum(int x){
    long long ans = 0;
    for(; x; x -= x&-x)
        ans += ft[x];
    return ans;
}

void prop(int u, int p, int big, int add){
    update(cnt[ c[u] ],-1);
    cnt[ c[u] ] += add;
    update(cnt[ c[u] ], 1);
    
    for(int v : g[u]) if(v != p && v != big){
        prop(v, u, big, add);    
    }
}

void dfs(int u, int p, bool soubig){
    int big = -1, mx = -1;

    for(int v : g[u]) if(v != p){
        if(sz[v] > mx) mx = sz[v], big = v;
    }

    for(int v : g[u]) if(v != p && v != big){
        dfs(v, u, false);
    }

    if(big != -1){
        dfs(big, u, true);
    }

    prop(u, p, big, 1);

    for(pair<int, int> q : query[u]){
        ans[q.ss] = sum(N) - sum(q.ff);
    }

    if(!soubig){
        prop(u, p, -1, -1);
    }
}


int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
        scanf("%d", c+i);

    for(int i = 1; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        query[a].push_back(mp(b, i));
    }

    dfs_cnt(1, 1);

    for(int i = 0; i < N; i++) cnt[i] = 1;

    dfs(1, 1, false);

    for(int i = 0; i < m; i++)
        printf("%d\n", ans[i]);

    return 0;
}
