#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 600005;

int n;

char s[100];

int t[N];

class Segtree{
    int n;
    vector<long long> st, lazy;

    void prop(int p){
        if(lazy[p]){
            st[p] = 0;
            lazy[2*p] = lazy[2*p+1] = 1;
            lazy[p] = 0;
        }
    }

    void update(int p, int L, int R, int i, int j, long long v){
        prop(p);
        if(j < L || i > R) return;
        if(L >= i && R <= j){ lazy[p] = 1, prop(p); return; }
        int mid = (L+R)/2;
        update(2*p, L, mid, i, j, v); update(2*p+1, mid+1, R, i, j, v);
        st[p] = max(st[2*p], st[2*p+1]);
    }

    void update(int p, int L, int R, int i, long long v){
        prop(p);
        if(i < L || i > R) return;
        if(R == i && i == L){ st[p] = v; return; }
        int mid = (L+R)/2;
        update(2*p, L, mid, i, v); update(2*p+1, mid+1, R, i, v);
        st[p] = max(st[2*p], st[2*p+1]);
    }

    int query(int p, int L, int R, int i, int j){
        prop(p);
        if(j < L || i > R) return 0;
        if(L >= i && R <= j) return st[p];
        int mid = (L+R)/2;
        return max(query(2*p, L, mid, i, j), query(2*p+1, mid+1, R, i, j));
    }

    public:
    Segtree(int sz = 0) : n(sz), st(8*sz, 0), lazy(8*sz, 0) {}

    void update(int i, long long v){ update(1, 1, n, i, v); }
    void update(int i, int j, long long v){ update(1, 1, n, i, j, v); }
    long long query(int i, int j){ return query(1, 1, n, i, j); }
};

int main(){

    scanf("%d", &n);

    int x;
    int last = -1;
    int prox = 1;
    stack<int> ss;
    set<int> erased;
    int ans = 0;

    Segtree st(n);

    for(int i = 1; i <= 2*n; i++){
        scanf(" %s", s);

        while(!ss.empty() && !erased.empty() && erased.count(ss.top())) ss.pop();

        if(s[0] == 'a'){
            scanf("%d", &x);
            ss.push(x);
            t[x] = i;
            st.update(x, i);
        }
        else{
            if(ss.top() == prox){
                ss.pop();
            }
            else if(t[prox] <= last){
                if(t[prox] < st.query(1, n)){
                    last = i;
                    ans++;
                st.update(1, n, 0);
                }
            }
            else{
                last = i;
                ans++;
                st.update(1, n, 0);
            }
            st.update(prox, 0);
            t[prox] = 0;

            erased.insert(prox);

            prox++;
        }
    }
    printf("%d\n", ans);


    return 0;
}
