#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 1000006;

char s[N];

int n, m;

class Segtree{
    int n;
    vector<int> st, f, a;

    //<<st, a>, f>
    pair<pair<int, int>, int > query(int p, int L, int R, int i, int j){
        if(j < L || i > R) return mp(mp(0, 0), 0);
        if(L >= i && R <= j) return mp(mp(st[p], a[p]), f[p]);
        int mid = (L+R)/2;
        pair<pair<int, int>, int> r1, r2, ret;

        r1 = query(2*p, L, mid, i, j);
        r2 = query(2*p+1, mid+1, R, i, j);
        int tmp = min(r1.ff.ss, r2.ss);
        ret.ff.ff = r1.ff.ff + r2.ff.ff + tmp;
        ret.ff.ss = r1.ff.ss + r2.ff.ss - tmp;
        ret.ss = r1.ss + r2.ss - tmp;
        return ret;
    }

    void build(int p, int L, int R, const string& s){
        if(L == R){
            if(s[L-1] == ')') f[p]++;
            if(s[L-1] == '(') a[p]++;
            return;
        }

        int mid = (L+R)/2;

        build(2*p, L, mid, s);
        build(2*p+1, mid+1, R, s);
        st[p] = st[2*p] + st[2*p+1];
        int tmp = min(a[2*p], f[2*p+1]);
        st[p] += tmp;
        a[p] = a[2*p] + a[2*p+1] - tmp;
        f[p] = f[2*p] + f[2*p+1] - tmp;
    }

public:
    Segtree(int sz, const string& s): n(sz), st(4*sz, 0), f(4*sz, 0), a(4*sz, 0) { build(1, 1, n, s);}

    int query(int i, int j){ return 2*query(1, 1, n, i, j).ff.ff; }

};


int main(){

    scanf("%s", s);

    n = strlen(s);

    scanf("%d", &m);

    Segtree st(n, s);

    for(int i = 0; i < m; i++){
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", st.query(l, r));
    }


    return 0;
}
