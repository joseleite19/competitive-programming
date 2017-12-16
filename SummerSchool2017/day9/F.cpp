#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

#define forn(i, n) for(int i = 0; i < int(n); i++)

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

typedef pair<int, int> pi;
const int N = 1000006;

int n, v[N];

class Segtree{
    int n;
    vector<pi> st;

    pi query(int p, int L, int R, int i, int j){
        if(i > R || j < L) return mp(0, -1);
        if(L >= i && R <= j) return st[p];
        int mid = (L+R)/2;
        return max(query(2*p, L, mid, i, j), query(2*p+1, mid+1, R, i, j));
    }

    void update(int p, int L, int R, int i, int v, int id){
        if(i > R || i < L) return;
        if(i == L && i == R){ st[p] = max(st[p], mp(v, id)); return; }
        int mid = (L+R)/2;
        update(2*p, L, mid, i, v, id);
        update(2*p+1, mid+1, R, i,v, id);
        st[p] = max(st[2*p], st[2*p+1]);
    }

public:
    Segtree(int sz = 0) : n(sz), st(4*sz, mp(0, -1)) {}
    pi query(int i, int j){ return query(1, 0, n-1, i, j); }
    void update(int i, int v, int id){
        update(1, 0, n-1, i, v, id);
    }
};

int p[N], ans[N];

void print(int id){
    if(p[id] == -1){
        printf("%d", v[id]);
        return;
    }
    print(p[id]);
    printf(" %d", v[id]);
}

int main(){

    file();

	scanf("%d", &n);
	forn(i, n) scanf("%d", v+i);

    Segtree st(N+1);

    memset(p, -1, sizeof p);
    forn(i, n){
        pi tmp = st.query(v[i], v[i]);
        if(v[i] >= 2) tmp = max(tmp, st.query(0, max(0, v[i]-2)));
        tmp = max(tmp, st.query(v[i]+2, N));
        p[i] = tmp.ss, ans[i] = tmp.ff+1;
        st.update(v[i], tmp.ff+1, i);
    }

    int mx = 0;

    forn(i, n) if(ans[i] >= ans[mx]) mx = i;

    printf("%d\n", n - ans[mx]);

    print(mx); printf("\n");
    
	return 0;
}
