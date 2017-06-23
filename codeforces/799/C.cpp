#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo (1000000000)
#define h(x) mp(x, oo)

using namespace std;

const int N = 100000;

int n, c, d, b[N], p[N];
vector< pair<int, int> > fc, fd;

class Segtree{
    vector<int> st;
    int n;

    int query(int p, int L, int R, int i, int j){
        if(j < L || i > R) return 0;
        if(L >= i && R <= j) return st[p];
        int mid = (L+R)/2;

        return max(query(2*p, L, mid, i, j), query(2*p+1, mid+1, R, i, j));    
    }

    void build(int p, int L, int R, vector<pair<int, int> > &f){
        if(L == R){ st[p] = f[L].ss; return; }
        if(L < R){
            int mid = (L + R) / 2;
            build(2*p, L, mid, f);
            build(2*p+1, mid+1, R, f);
            st[p] = max(st[2*p], st[2*p+1]);        
        }
    }
public:
    Segtree(int sz, vector<pair<int, int> > &f) : n(sz), st(4*sz, 0) {
        build(1, 0, n-1, f);
    }
    int query(int i, int j){
        if(j > i) return 0;
        return query(1, 0, n-1, i, j);
    }
};

int main(){

    scanf("%d %d %d", &n, &c, &d);

    for(int i = 0; i < n; i++){
        int b, p;
        char c;
        scanf("%d %d %c", &b, &p, &c);
        if(c == 'C') fc.push_back(mp(p, b));
        if(c == 'D') fd.push_back(mp(p, b));
    }

    sort(fc.begin(), fc.end());
    sort(fd.begin(), fd.end());

    Segtree sc(n, fc), sd(n, fd);

    int ans = 0;

    for(int i = 0; i < fc.size(); i++){
        int cc = c - fc[i].ff, dd = d;
        if(cc < 0) continue;
        int id = upper_bound(fc.begin(), fc.end(), h(cc)) - fc.begin() - 1;
        int id2= upper_bound(fd.begin(), fd.end(), h(dd)) - fd.begin() - 1;
        int tmp= i;

        if(id2 >= 0){
            int q = sd.query(0, id2);
            if(q) ans = max(ans, q+fc[i].ss);
        }
        if(id >= 0){
            int q = max(sc.query(0, tmp-1), sc.query(tmp+1, id));
            if(q) ans = max(ans, q+fc[i].ss);
        }
        //[0, tmp-1] [tmp+1, id]
        //[0, id2]
    }

    for(int i = 0; i < fd.size(); i++){
        int cc = c, dd = d - fd[i].ff;
        if(dd < 0) continue;

        int id2= upper_bound(fc.begin(), fc.end(), h(cc)) - fc.begin() - 1;
        int id = upper_bound(fd.begin(), fd.end(), h(dd)) - fd.begin() - 1;
        int tmp= i;

        if(id2 >= 0){
            int q = sc.query(0, id2);
            if(q) ans = max(ans, q+fd[i].ss);
        }
        if(id >= 0){
            int q = max(sd.query(0, tmp-1), sd.query(tmp+1, id));
            if(q) ans = max(ans, q+fd[i].ss);
        }

    }
    printf("%d\n", ans);


    return 0;
}
