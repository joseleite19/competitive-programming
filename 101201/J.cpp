#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;


class Segtree{

    vector<long long> st;
    int n;

    void update(int p, int L, int R, int i, long long val){
        if(L > i || i > R) return;
        if(L == i && i == R){
            st[p] = val;
            return;
        }
        int mid = (L+R)/2;
        update(2*p, L, mid, i, val);
        update(2*p+1, mid+1, R, i, val);
        st[p] = min(st[2*p], st[2*p+1]);
    }

    long long query(int p, int L, int R, int i, int j){
        if(L > j || i > R) return 0;
        if(L >= i && j >= R){
            return st[p];
        }
        int mid = (L+R)/2;
        return min(query(2*p, L, mid, i, j), query(2*p+1, mid+1, R, i, j));
    }

    int query(int p, int L, int R, int i, int j, long long val){
        if(L > j || i > R) return -1;
        if(val < st[p]) return -1;
        if(L == R) return L;

        int mid = (L+R)/2;
        int ret = query(2*p, L, mid, i, j, val);
        if(ret == -1) ret = query(2*p+1, mid+1, R, i, j, val);
        return ret;
    }

public:
    Segtree(int sz = 0) : n(sz), st(4*sz, 0) {}

    long long query(int i, int j){
        return query(1, 1, n, i, j);
    }

    int query(int i, int j, long long val){
        return query(1, 1, n, i, j, val);
    }

    void update(int i, long long val){
        update(1, 1, n, i, val);
    }


};

int n, q;

long long a[200005], v[200005];

int main(){

    scanf("%d %d", &n, &q);

    for(int i = 1; i <= n; i++)
        scanf("%lld", a+i);

    Segtree st(n);

    for(int i = 1; i <= n; i++)
        st.update(i, a[i]);

    while(q--){
        int l, r;
        long long v;

        scanf("%lld %d %d", &v, &l, &r);
        while(l <= r){
            l = st.query(l, r, v);
            if(l == -1) break;
            v %= a[l];
        }

        printf("%lld\n", v);    
    }

    return 0;
}
