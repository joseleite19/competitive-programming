#include <bits/stdc++.h>

using namespace std;

class Segtree{
    int n;
    vector<long long> st;

    void update(int p, int L, int R, int i, long long val){
        if(L > i || i > R) return;
        if(L == i && i == R) { st[p] = val; return; }
        int mid = (L+R)/2;
        update(2*p, L, mid, i, val);
        update(2*p+1, mid+1, R, i, val);
        st[p] = max(st[2*p], st[2*p+1]);
    }

    long long query(int p, int L, int R, int i, int j){
        if(j < L || i > R) return 0;
        if(L >= i && R <= j) return st[p];
        int mid = (L+R)/2;
        return max(query(2*p, L, mid, i, j), query(2*p+1, mid+1, R, i, j));
    }

public:
    Segtree(int sz = 0) : n(sz), st(4*sz, 0) {}

    long long query(int i, int j){ return query(1, 0, n-1, i, j); }
    void update(int i, long long val) { update(1, 0, n-1, i, val); }

};

const int N = 300005;

int n;
long long v[N];
int en[N], start[N];

long long f(long long x, long long tam){
    tam = min(tam, x);

    return x*tam - tam*(tam-1)/2;
}

int main(){

    int q;
    scanf("%d %d", &n, &q);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    Segtree st(n);

    for(int i = 0; i < n; ){
        int j = i;
        while(j < n && v[i] == v[j]) j++;
        for(int q = i; q < j; q++)
            en[q] = j-1, start[q] = i;
        st.update(i, f(v[i], j - i));
        i = j;
    }

    int l, r;
    while(q--){
        scanf("%d %d", &l, &r); l--, r--;

        if(en[l] >= r){
            printf("%lld\n", f(v[l], r - l + 1));
            continue;
        }
        long long ans = 0;
        ans = f(v[l], en[l] - l + 1);
        ans = max(ans, f(v[r], r - start[r] + 1));
        l = en[l]+1;
        r = start[r]-1;
        if(l <= r) ans = max(ans, st.query(l, r));
        printf("%lld\n", ans);
    }


    return 0;
}


