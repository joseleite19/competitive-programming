#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define eb emplace_back

using namespace std;
using namespace __gnu_pbds;

const int N = 1 << 16;
const int sq= 1 <<  8;

int n, q;
int c[N], back[N], ans[N];

vector<int> g[N];

struct cd{
    int u, v, k, id, add;
    cd(int u = 0, int v = 0, int k = 0, int add = 0, int id = 0):
        u(u), v(v), k(k), add(add), id(id){}
    bool operator<(const cd &o) const{
        if(u / sq != o.u / sq) return u / sq < o.u / sq;
        return v < o.v;
    }
};

int t = 1, st[N], en[N], s[N];
int L[N];
int p[N];
void dfs(int u){
    s[t] = u;
    st[u] = t++;

    for(int v : g[u]) if(v != p[u]){
        L[v] = L[u]+1;
        p[v] = u;
        dfs(v);
    }

    s[t] = u;
    en[u] = t++;
}

int dp[N][33];
int f(int u, int lg){
    if(lg == 0) return p[u];
    if(~dp[u][lg]) return dp[u][lg];
    return dp[u][lg] = f(f(u, lg-1), lg-1);
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
        if((1 << lg) > L[u]) continue;
        if(f(u, lg) != f(v, lg)){
            u = f(u, lg);
            v = f(v, lg);
        }
    }

    return p[u];
}

typedef tree<
int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

int ft[N+1];
int cnt[N];

int all;
int freq[N];
ordered_set ss[N];

void remove(int);

void sum(int x, int v){
    for(; x <= N; x += x&-x)
        ft[x] += v;
}

void add(int x){
    if(cnt[ s[x] ]){
        remove(x);
        return;
    }

    cnt[ s[x] ] = 1;

    int v = c[ s[x] ];

    if(freq[v]){
        ss[ freq[v] ].erase(v);
        all--;
        sum(freq[v],-1);
    }

    freq[v]++;
    all++;
    ss[ freq[v] ].insert(v);
    sum(freq[v], 1);
}

void remove(int x){
    if(!cnt[ s[x] ]){
        add(x);
        return;
    }
    cnt[ s[x] ] = 0;

    int v = c[ s[x] ];

    ss[ freq[v] ].erase(v);
    all--;
    sum(freq[v],-1);

    freq[v]--;
    if(freq[v]){
        all++;
        ss[ freq[v] ].insert(v);
        sum(freq[v], 1);
    }
}

int find(int k){
    int L = 1, R = N;

    //printf("%d %d\n", all, k);
    k = all - k + 1;

    //for(int i = 0; i < N; i++) if(freq[i]) printf("(%d %d) ", i, freq[i]);
    //printf("\n");

    while(L+1 < R){
        int mid = (L+R)/2;
        //printf("[%d %d] %d %d\n", L, R, k, ft[mid]); 
        if(ft[mid] >= k){
            R = mid;
        }
        else{
            k -= ft[mid];
            L = mid+1;
        }
    }
    if(ft[L] >= k) k -= ft[L], R = L;
    printf(";;;;%d %d %d\n", R, k, int(ss[R].size()));
    return *ss[R].find_by_order(k);
}

int main(){

    memset(dp, -1, sizeof dp);

    scanf("%d %d", &n, &q);

    for(int i = 1; i <= n; i++)
        scanf("%d", c+i);

    {
        set<int> s;
        for(int i = 1; i <= n; i++) s.insert(c[i]);
        int ptr = 1;
        map<int, int> go;
        for(int x : s){
            go[x] = ptr;
            back[ptr] = x;
            ptr++;
        }
        for(int i = 1; i <= n; i++) c[i] = go[ c[i] ];
    }

    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    vector<cd> ev;

    for(int i = 0; i < q; i++){
        int u, v, k;
        scanf("%d %d %d", &u, &v, &k);
        if(st[u] > st[v]) swap(u, v);

        int lca = LCA(u, v);

        if(lca == u) ev.eb(st[u], st[v], k, 0, i);
        else ev.eb(en[u], st[v], k, lca, i);
    }

    sort(ev.begin(), ev.end());

    int L = 1, R = 0;

    for(int i = 0; i < ev.size(); i++){
        while(R > ev[i].v) remove(R--);
        while(R < ev[i].v) add(++R);
        while(L > ev[i].u) add(--L);
        while(L < ev[i].u) remove(L++);

        if(ev[i].add) add(ev[i].add);

        ans[ ev[i].id ] = back[ find(ev[i].k) ];
        
        if(ev[i].add) remove(ev[i].add);
    }


    for(int i = 0; i < q; i++)
        printf("%d\n", ans[i]);



    return 0;
}
