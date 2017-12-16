#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000007LL
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 200005;

int p[N], L[N], vis[N], dp[N][22], pw[N], dp2[N][22]; 
vector<int> g[N];
struct Segtree{
    int n;
    vector<ll> st, lazy;

    void prop(int p, int L, int R){
        if(lazy[p]){
            st[p] = (R - L + 1) - st[p];
            if(L != R) lazy[2*p] ^= lazy[p], lazy[2*p+1] ^= lazy[p];
            lazy[p] = 0;
        }
    }

    void update(int p, int L, int R, int i, int j){
        prop(p, L, R);
        if(L > j || R < i) return;
        if(L >= i && R <= j){
            lazy[p] = 1;
            prop(p, L, R);
            return;
        }
        int mid = (L+R)/2;
        update(2*p, L, mid, i, j);
        update(2*p+1, mid+1, R, i, j);
        st[p] = st[2*p] + st[2*p+1];
    }
    ll query(int p, int L, int R, int i, int j){
        prop(p, L, R);
        if(L > j || R < i) return 0;
        if(L >= i && R <= j) return st[p];
        int mid = (L+R)/2;
        return query(2*p, L, mid, i, j) + query(2*p+1, mid+1, R, i, j);
    }

public:
    Segtree(int sz = 0) : n(sz), st(4*sz, 0), lazy(4*sz, 0){}

    void update(int i, int j){
        update(1, 1, n, i, j);
    }
    ll query(int i, int j){
        return query(1, 1, n, i, j);
    }
};

int s[N], f[N], tempo;
void dfs_cnt(int u){
    s[u] = ++tempo;
    for(int v : g[u]) L[v] = L[u]+1, dfs_cnt(v);
    f[u] = tempo;
}

int t[N];

char w[10];

int main(){
    int n;

    scanf("%d", &n);

    p[1] = L[1] = 1;
    fore(i, 2, n) scanf("%d", p+i), g[p[i]].pb(i);
    dfs_cnt(1);

    for1(i, n) scanf("%d", t+i);
    
    Segtree st(tempo+2);

    for1(i, n) if(t[i]) st.update(s[i], s[i]);
    int q, x;

    scanf("%d", &q);

    forn(i, q){
        scanf(" %s %d", w, &x);
        if(w[0] == 'g') printf("%lld\n", st.query(s[x], f[x]));
        else st.update(s[x], f[x]);
    }

    return 0;
}
