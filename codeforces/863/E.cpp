#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000007LL
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define fore(i, n) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 200005;

struct Segtree{
    int n;
    vector<ll> st, lazy;

    void prop(int p, int L, int R){
        if(lazy[p]){
            st[p] += lazy[p];
            if(L != R) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
            lazy[p] = 0;
        }
    }

    void update(int p, int L, int R, int i, int j, ll v){
        prop(p, L, R);
        if(L > j || R < i) return;
        if(L >= i && R <= j){
            lazy[p] = v;
            prop(p, L, R);
            return;
        }
        int mid = (L+R)/2;
        update(2*p, L, mid, i, j, v);
        update(2*p+1, mid+1, R, i, j, v);
        st[p] = min(st[2*p], st[2*p+1]);
    }
    ll query(int p, int L, int R, int i, int j){
        prop(p, L, R);
        if(L > j || R < i) return oo;
        if(L >= i && R <= j) return st[p];
        int mid = (L+R)/2;
        return min(query(2*p, L, mid, i, j), query(2*p+1, mid+1, R, i, j));
    }
public:
    Segtree(int sz = 0) : n(sz), st(4*sz, 0), lazy(4*sz, 0){}

    void update(int i, int j, ll v){
        update(1, 1, n, i, j, v);
    }
    ll query(int i, int j){
        return query(1, 1, n, i, j);
    }
};

vector<pair<int, int> > v;

int main(){

    int n;

    scanf("%d", &n);

    forn(i, n){
        int a, b;
        scanf("%d %d", &a, &b);
        v.eb(a, b);
    }

    int p = 1;
    {
        set<int> s;
        map<int, int> go;
        forn(i, n) s.insert(v[i].ff), s.insert(v[i].ff-1), s.insert(v[i].ss), s.insert(v[i].ss+1);

        for(int x : s) go[x] = p++;

        forn(i, n) v[i].ff = go[ v[i].ff ], v[i].ss = go[ v[i].ss ];
    }

    Segtree st(p);

    forn(i, n) st.update(v[i].ff, v[i].ss, 1);

    forn(i, n) if(st.query(v[i].ff, v[i].ss) > 1)
        return printf("%d\n", i+1), 0;
    
    printf("-1\n");
}
