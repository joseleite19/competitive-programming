#include <bits/stdc++.h>

using namespace std;

const int N = 260*260;

int s[N], t[N];

int n, m;

int tr[N];

class Segtree{

    int n;
    vector<int> st;

    void update(int p, int L, int R, int i, int v){
        if(i < L || i > R) return;
        if(R == i && i == L){ st[p] = max(st[p], v); return; }
        int mid = (L+R)/2;
        update(2*p, L, mid, i, v); update(2*p+1, mid+1, R, i, v);
        st[p] = max(st[2*p], st[2*p+1]);
    }
    
    int query(int p, int L, int R, int i, int j){
        if(j < L || i > R) return 0;
        if(L >= i && R <= j) return st[p];
        int mid = (L+R)/2;
        return max(query(2*p, L, mid, i, j), query(2*p+1, mid+1, R, i, j));
    }

public:
    Segtree(int sz = 0) : n(sz), st(4*sz, 0){}

    void update(int i, int v){ update(1, 0, n-1, i, v); }
    int query(int i, int j){ return query(1, 0, n-1, i, j); }
};

int main(){

    int T;

    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++){
        int sz;
        scanf(" %d %d %d", &sz, &n, &m); n++, m++; sz *= sz;
        memset(tr, -1, sizeof tr);
        for(int i = 0; i < n; i++) scanf("%d", s+i), tr[ s[i] ] = i;
        for(int i = 0; i < m; i++) scanf("%d", t+i), t[i] = tr[ t[i] ];

        Segtree st(N + 10);

        int ans = 0;
        for(int i = 0; i < m; i++){
            if(t[i] == -1) continue;
            int tmp = st.query(0, t[i]) + 1;
            ans = max(ans, tmp);
            st.update(t[i], tmp);
        }

        assert(ans >= 2);

        printf("Case %d: %d\n", tc, ans);
    }


    return 0;
}
