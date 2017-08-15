#include <bits/stdc++.h>

#define MOD 1000000009LL

using namespace std;

class Segtree{
    int n;
    vector<long long> st, lazy;

    void push(int p, int L, int R){
        if(lazy[p]){
            st[p] = (st[p] + lazy[p] * (R-L+1)) % MOD;
            if(L != R){
                lazy[2*p] = (lazy[2*p] + lazy[p]) % MOD;
                lazy[2*p+1] = (lazy[2*p+1] + lazy[p]) % MOD;
            }
            lazy[p] = 0;
        }
    }

    void update(int p, int L, int R, int i, int j, long long v){
        push(p, L, R);
        if(i > R || j < L) return;
        if(L >= i && R <= j){
            lazy[p] = v;
            push(p, L, R);
            return;
        }
        int mid = (L+R)/2;
        update(2*p, L, mid, i, j, v);
        update(2*p+1, mid+1, R, i, j, v);
        st[p] = (st[2*p] + st[2*p+1]) % MOD;
    }

    long long query(int p, int L, int R, int i, int j){
        push(p, L, R);
        if(i > R || j < L) return 0;
        if(L >= i && R <= j) return st[p];
        int mid = (L+R)/2;
        return (query(2*p, L, mid, i, j) +
                query(2*p+1, mid+1, R, i, j)) % MOD;
    }

public:
    Segtree(int sz = 0) : n(sz), st(4*sz, 0), lazy(4*sz, 0) {}
    void update(int i, int j, long long v){ update(1, 1, n, i, j, v); }
    long long query(int i, int j){ return query(1, 1, n, i, j); }
};

const int N = 300005;
long long fib[N];

int main(){

    fib[1] = fib[2] = 1;

    for(int i = 3; i < N; i++)
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;

    int n, m;

    scanf("%d %d", &n, &m);

    Segtree st(n);

    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        st.update(i, i, x);
    }


    while(m--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1) st.update(b, c, fib[c-b+1]);
        else printf("%lld\n", st.query(b, c));
    for(int i = 1; i <= n; i++)
        printf("%lld ", st.query(i, i));
    printf("\n");
    }


    return 0;
}
