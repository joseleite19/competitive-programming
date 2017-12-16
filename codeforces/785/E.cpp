#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000007LL
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 200005;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> oset;

class mst{
    int n;
    vector<oset> st;

    inline void build(int p, int L, int R){

        fore(i, L, R) st[p].insert(i);

        if(L != R){
            int mid = (L+R)/2;
            build(2*p, L, mid), build(2*p+1, mid+1, R);
        }
    }

    inline int update(int p, int L, int R, int i, int v){
        if(L == R){
            int x = *st[p].begin();
            st[p].erase(x), st[p].insert(v);
            return x;
        }
        int mid = (L+R)/2;
        int x;
        if(i <= mid) x = update(2*p, L, mid, i, v);
        else x = update(2*p+1, mid+1, R, i, v);
        st[p].erase(x), st[p].insert(v);
    }

    inline int query(int p, int L, int R, int i, int j, int x){
        if(L > j || R < i) return 0;
        if(L == R) return st[p].order_of_key(x);
        int mid = (L+R)/2;
        return query(2*p, L, mid, i, j, x) +
               query(2*p+1, mid+1, R, i, j, x);
    }

public:
    mst(int sz) : n(sz), st(4*sz){
        build(1, 0, n-1);
    }
    inline void update(int i, int v){
        update(1, 0, n-1, i, v);
    }

    //qnt de numeros menores que x no range [i, j]
    inline int query(int i, int j, int x){
        return query(1, 0, n-1, i, j, x);
    }
};

int v[N];

int main(){

    int n;

    scanf("%d", &n);

    forn(i, n) v[i] = i;

    mst st(n);

    int q, a, b;

    scanf("%d", &q);

    ll ans = 0;
    while(q--){
        scanf("%d %d", &a, &b); a--, b--;
        if(a > b) swap(a, b);
        if(a != b){
            if(a + 1 < b)
                ans += 2*(st.query(a+1, b-1, v[b]) - st.query(a+1, b-1, v[a]));
            ans += (v[a] < v[b] ? 1 : -1);
            swap(v[a], v[b]);
            st.update(a, v[a]), st.update(b, v[b]);
        }
        printf("%lld\n", ans);
    }


    return 0;
}
