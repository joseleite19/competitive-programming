#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back

using namespace std;

const int N = 200005;

class Segtree{

    const int n;
    vector<long long> st, lazy;
    
    void push(int p, int L, int R){
        if(lazy[p]){
            st[p] += lazy[p];
            if(L != R) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
            lazy[p] = 0;
        }
    }
public:
    Segtree(int sz = 0) : n(sz), st(4*sz, 0), lazy(4*sz, 0) {}

    long long query(int i, int j, int p, int L, int R){
        push(p, L, R);
        if(i > R || j < L) return 0;
        if(R >= i && L <= j) return st[p];
        int mid = (L+R)/2;
        return max(query(i, j, 2*p, L, mid),
                  query(i, j, 2*p+1, mid+1, R));
    }
    void update(int i, int j, long long v, int p, int L, int R){
        push(p, L, R);
        if(i > R || j < L) return;
        if(R >= i && L <= j){ lazy[p] += v; push(p, L, R); return; }
        int mid = (L+R)/2;
        update(i, j, v, 2*p, L, mid);
        update(i, j, v, 2*p+1, mid+1, R);
        st[p] = max(st[2*p], st[2*p+1]);
    }
    long long query(int i, int j){
        return query(i, j, 1, 1, n);
    }
    void update(int i, int j, long long v){
        update(i, i, v, 1, 1, n);
    }
};

int color[N];
int cycle[N], found;

vector<pair<int, int> > g[N];

bool dfs(int u){
    color[u] = 1;
    int ret = false;
    for(pair<int, int> x : g[u]){
        if(found) return false;

        int v = x.ss;
        if(color[v] == 0){
            if(dfs(v)){
                if(cycle[u]) ret = false;
                else ret = cycle[u] = true;
                break;
            }
        }
        else if(color[v] == 1){
            found = true;
            ret = cycle[v] = cycle[u] = 1;
            break;
        }
    }
    color[u] = 2;
    return false;
}


int main(){
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].eb(v, w);
        g[v].eb(u, w);
    }


    return 0;
}

