#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

class Segtree{

    int n;
    vector<int> st;

    void update(int p, int L, int R, int i, int v){
        if(i < L || i > R) return;
        if(L == i && R == i){ st[p] = max(st[p], v); return; }
        int mid = (L+R)/2;
        update(2*p, L, mid, i, v);
        update(2*p+1, mid+1, R, i, v);
        st[p] = max(st[2*p], st[2*p+1]);
    }

    int query(int p, int L, int R, int i, int j){
        if(j < L || i > R) return 0;
        if(L >= i && R <= j) return st[p];
        int mid = (L+R)/2;
        return max(query(2*p, L, mid, i, j), query(2*p+1, mid+1, R, i, j));
    }

public:

    Segtree(int sz = 0) : n(sz), st(4*sz, 0) {}

    void update(int i, int v){ update(1, 0, n-1, i, v); }
    int query(int i, int j){ return query(1, 0, n-1, i, j); }

};

const int N = 100005;

pair<long long, pair<long long, int> > p[N];

int ans[N];

int main(){

    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%lld %lld", &p[i].ff, &p[i].ss.ff);
        p[i].ss.ss = i;
    }

    sort(p, p+n);

    int ptr = 1;
    map<long long, long long> mm;
    {
        set<long long> s;
        for(int i = 0; i < n; i++)
            s.insert(p[i].ff), s.insert(p[i].ff+1), s.insert(p[i].ff + p[i].ss.ff-1);
        for(long long x : s)
            mm[x] = ptr++;
    }

    Segtree st(ptr);
    for(int i = n-1; i >= 0; i--){
        int tmp = max(i, st.query(mm[ p[i].ff+1 ], mm[ p[i].ff + p[i].ss.ff-1 ]));
        ans[ p[i].ss.ss ] = tmp - i + 1;
        st.update(mm[ p[i].ff ], tmp);
    }

    for(int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");

}
