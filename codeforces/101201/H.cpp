#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

class Segtree{

    vector<long long> st;
    int n;

    void update(int p, int L, int R, int i, long long val){
        if(L > i || i > R) return;
        if(L == i && i == R){
            st[p] = max(st[p], val);
            return;
        }
        int mid = (L+R)/2;
        update(2*p, L, mid, i, val);
        update(2*p+1, mid+1, R, i, val);
        st[p] = max(st[2*p], st[2*p+1]);
    }

    long long query(int p, int L, int R, int i, int j){
        if(L > j || i > R) return 0;
        if(L >= i && j >= R){
            return st[p];
        }
        int mid = (L+R)/2;
        return max(query(2*p, L, mid, i, j), query(2*p+1, mid+1, R, i, j));
    }

public:
    Segtree(int sz = 0) : n(sz), st(4*sz, 0) {}

    long long query(int i, int j){
        return query(1, 1, n, i, j);
    }
    void update(int i, long long val){
        update(1, 1, n, i, val);
    }


};

long long n, k, a[200005], b[200005];

int main(){

    scanf("%lld %lld", &n, &k);

    for(int i = 0; i < k; i++)
        scanf("%lld %lld", a+i, b+i);

    vector<pair<pair<int, int>, long long> > v; // <<R, L>, cost>

    int ptr = 1;
    {
        map<long long, int> vai;
        set<long long> ss;

        for(int i = 0; i < k; i++)
            ss.insert(a[i]), ss.insert(b[i]);

        for(long long x : ss)
            vai[x] = ptr++;

        for(int i = 0; i < k; i++){
            v.push_back(mp(mp(vai[ b[i] ], vai[ a[i] ] ), b[i] - a[i] + 1));
        }
        sort(v.begin(), v.end());
    }

    Segtree st(ptr+10);

    long long ans = 0;

    for(int i = 0; i < k; i++){
        long long tmp = st.query(1, v[i].ff.ss-1) + v[i].ss;
        st.update(v[i].ff.ff, tmp);
        ans = max(ans, tmp);
    }

    printf("%lld\n", n - ans);


}
