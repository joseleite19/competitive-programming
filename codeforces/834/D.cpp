#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back

using namespace std;

const int N = 35004;

class Segtree{
    int n;
    vector<int> st, lazy;

    void prop(int p){
        if(lazy[p]){
            lazy[2*p] += lazy[p];
            lazy[2*p+1]+=lazy[p];
            st[p] += lazy[p];
            lazy[p] = 0;
        }
    }

    void update(int p, int L, int R, int i, int j, int v){
        prop(p);
        if(i > R || j < L) return;
        if(L >= i && R <= j){
            lazy[p] = v;
            prop(p);
            return;
        }
        int mid = (L+R)/2;
        update(2*p, L, mid, i, j, v);
        update(2*p+1, mid+1, R, i, j, v);
        st[p] = max(st[2*p], st[2*p+1]);
    }

    int query(int p, int L, int R, int i, int j){
        prop(p);
        if(i > R || j < L) return 0;
        if(L >= i && R <= j) return st[p];
        int mid = (L+R)/2;
        return max(query(2*p, L, mid, i, j),
                query(2*p+1, mid+1, R, i, j));
    }


public:
    Segtree(int sz = 0) : n(sz), st(8*sz, 0), lazy(8*sz, 0) {}

    void update(int i, int j, int v){
        update(1, 1, n, i, j, v);
    }
    int query(int i, int j){
        return query(1, 1, n, i, j);
    }
};

int v[N];

int last[N];

int main(){

    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++)
        scanf("%d", v+i);

    {
        int tmp[N];
        memset(tmp, 0, sizeof tmp);

        for(int i = 1; i <= n; i++){
            last[i] = tmp[ v[i] ];
            tmp[ v[i] ] = i;
        } 
    }

    Segtree st(n);

    int ans = 0;

    for(int i = 1; i <= n; i++){
        if(last[i] == 0) st.update(i, i, 1);
        st.update(i, i, st.query(1, i-1));
    }

    for(int j = 1; j < k; j++){
        vector<int> tmp(n+1);;
        for(int i = 1; i <= n; i++){
            last[i], i;
            if(last[i] != i) st.update(last[i], i-1, 1);
            tmp[i] = st.query(1, i);
        }

        for(int i = 1; i <= n; i++)
            st.update(i, i, tmp[i] - st.query(i, i));
    }

    printf("%d\n", st.query(1, n));






    return 0;
}
