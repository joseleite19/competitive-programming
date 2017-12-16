#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;

int n, m;
ll sum[N];
vector<pair<int,int> > l[N];

class Segtree{
    int n;
    vector<int> st;
    void update(int p, int L, int R, int x, int v){
        if(x < L || x > R) return;
        if(L == x && x == R){ st[p] = min(st[p], v); return; }
        int mid = (L+R)/2;
        update(2*p, L, mid, x, v);
        update(2*p+1, mid+1, R, x, v);
        st[p] = min(st[2*p], st[2*p+1]);
    }

    int query(int p, int L, int R, int i, int j){
        if(j < L || i > R) return MOD;
        if(L >= i && R <= j) return st[p];
        int mid = (L+R)/2;
        return min(query(2*p, L, mid, i, j),
                query(2*p+1, mid+1, R, i, j));
    }

public:
    Segtree(int sz = 0) : n(sz), st(4*sz, MOD){}
    void update(int x, int v){ update(1, 1, n, x, v); }
    int query(int i, int j){ return query(1, 1, n, i, j); }
};


int main(){

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        sum[i] = sum[i-1] + x;
    }
    sum[n+1] = sum[n];

    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        l[a].eb(b, c);
    }

    Segtree st(n+1);
    st.update(n+1, 0);

    for(int i = n; i >= 1; i--){
        for(auto x : l[i]){
            int lo = i, hi = n+1;
            while(lo+1 < hi){
                int mid = (lo + hi) / 2;
                if(sum[mid-1] - sum[i-1] <= x.ff){
                    lo = mid;
                }
                else hi = mid-1;
            }
            if(sum[hi-1] - sum[i-1] > x.ff) hi = lo;
            //printf("%d %d %d\n", i, hi, st.query(i, hi));
            st.update(i, st.query(i, hi) + x.ss);
        }
    }

    int ans = st.query(1, 1);
    if(ans >= MOD) ans = -1;
    printf("%d\n", ans);



    return 0;
}
