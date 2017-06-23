#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

long long t[N], l[N], r[N];

class Segtree{
    int n;
    vector<int> st, lazy; // 1 - makeone; 2 - makezero; 3 - invert

    void prop(int p, int L, int R){
        if(lazy[p]){
            if(lazy[p] == 1){
                st[p] = R-L+1;
                lazy[2*p] = lazy[2*p+1] = lazy[p];
            }
            else if(lazy[p] == 2){
                st[p] = 0;
                lazy[2*p] = lazy[2*p+1] = lazy[p];
            }
            else if(lazy[p] == 3){
                st[p] = R-L+1 - st[p];
                lazy[2*p] = 3 - lazy[2*p];
                lazy[2*p+1] = 3 - lazy[2*p+1];
            }
        
            lazy[p] = 0;
        }
    }

    void makeone(int p, int L, int R, int i, int j){
        prop(p, L, R);
        if(j < L || i > R) return;
        if(L >= i && R <= j){
            lazy[p] = 1;
            prop(p, L, R);
            return;
        }
        int mid = (L+R)/2;
        makeone(2*p, L, mid, i, j);
        makeone(2*p+1, mid+1, R, i, j);
        st[p] = st[2*p] + st[2*p+1];
    }

    void makezero(int p, int L, int R, int i, int j){
        prop(p, L, R);
        if(j < L || i > R) return;
        if(L >= i && R <= j){
            lazy[p] = 2;
            prop(p, L, R);
            return;
        }
        int mid = (L+R)/2;
        makezero(2*p, L, mid, i, j);
        makezero(2*p+1, mid+1, R, i, j);
        st[p] = st[2*p] + st[2*p+1];
    }
    
    void makeinv(int p, int L, int R, int i, int j){
        prop(p, L, R);
        if(j < L || i > R) return;
        if(L >= i && R <= j){
            lazy[p] = 3;
            prop(p, L, R);
            return;
        }
        int mid = (L+R)/2;
        makeinv(2*p, L, mid, i, j);
        makeinv(2*p+1, mid+1, R, i, j);
        st[p] = st[2*p] + st[2*p+1];
    }
    int tmp; 
    int query(int p, int L, int R){
        prop(p, L, R);
        if(L == R) return L;

        int mid = (L+R)/2;
        prop(2*p, L, mid), prop(2*p+1, mid+1, R);
        //if(tmp == 4) printf("%d %d %d [%d %d]\n", st[p], st[2*p], st[2*p+1], L, R);
        if(st[2*p] < mid - L + 1) return query(2*p, L, mid);
        return query(2*p+1, mid+1, R);
    }

public:
    Segtree(int sz) : n(sz), st(8*sz, 0), lazy(8*sz, 0), tmp(0){}        
    
    void makeone(int i, int j){ makeone(1, 0, n-1, i, j); }
    void makezero(int i, int j){ makezero(1, 0, n-1, i, j); }
    void makeinv(int i, int j){ makeinv(1, 0, n-1, i, j); }
    int query(){ tmp++; return query(1, 0, n-1); }
};

int main(){

    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld %lld %lld", t+i, l+i, r+i);

    map<long long, int> vai;
    map<int, long long> volta;
    int ptr = 0;
    {
        set<long long> s;
        s.insert(1);
        for(int i = 0; i < n; i++)
            s.insert(l[i]), s.insert(r[i]), s.insert(r[i]+1);
        for(long long q : s)
            volta[ptr] = q, vai[q] = ptr++;
        for(int i = 0; i < n; i++)
            l[i] = vai[ l[i] ], r[i] = vai[ r[i] ];
    }

    Segtree st(ptr);

    for(int i = 0; i < n; i++){
        if(t[i] == 1) st.makeone(l[i], r[i]);
        if(t[i] == 2) st.makezero(l[i], r[i]);
        if(t[i] == 3) st.makeinv(l[i], r[i]);
        printf("%lld\n", volta[ st.query() ]);
    }

    return 0;
}
