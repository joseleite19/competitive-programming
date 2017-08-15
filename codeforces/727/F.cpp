#include <bits/stdc++.h>

using namespace std;

const int N = 1003;

long long v[N];
long long sum[N];
long long cp[N];
int erased[N];
int n, m;

long long ans[N];

int id[N];

class Segtree{
    int n;
    vector<long long> st, lazy;

    inline void prop(int p, int L, int R){
        if(lazy[p]){
            st[p] += lazy[p];
            if(L != R) lazy[2*p] += lazy[p],
                       lazy[2*p+1] += lazy[p];
            lazy[p] = 0;
        }
    }

    void update(int p, int L, int R, int i, int j, long long v){
        prop(p, L, R);
        if(j < L || i > R) return;
        if(L >= i && R <= j){
            lazy[p] = v;
            prop(p, L, R);
            return;
        }
        int mid = (L+R)/2;

        update(2*p, L, mid, i, j, v);
        update(2*p+1, mid+1, R, i, j, v);
        st[p] = min(st[2*p], st[2*p+1]); 
    }

    long long query(int p, int L, int R, int i, int j){
        prop(p, L, R);
        if(j < L || i > R) return 1e18;
        if(L >= i && R <= j) return st[p];
        int mid = (L + R) / 2;
        return min(query(2*p, L, mid, i, j), query(2*p+1, mid+1, R, i, j));
    }


public:
    Segtree(int sz = 0) : n(sz), st(4*sz, 0), lazy(4*sz, 0) {}

    inline long long query(int i, int j){ return query(1, 0, n-1, i, j); }
    inline void update(int i, int j, long long v){
        update(1, 0, n-1, i, j, v);
    }
};

Segtree qwe;

int f(long long x){
    int ans = 0;

    /*Segtree cp = qwe;

    for(int i = 0; i < n; i++){
        if(x + cp.query(id[i], n-1) < 0){
            ans++;
            cp.update(id[i], n-1, -v[ id[i] ]);
        }
    }*/

    priority_queue<long long, vector<long long>, greater<long long> > pq;

    long long sum = 0;

    for(int i = 0; i < n; i++){
        sum += v[i];
        pq.push(v[i]);
        while(x + sum < 0){
            ans++;
            if(pq.empty()) return n;
            sum -= pq.top();
            pq.pop();
        }
    }


    return ans;
}

void findlow(int x){
    long long hi = 1e18, lo = -1e18;

    while(lo + 1 < hi){
        long long mid = (lo + hi) / 2;
        int tmp = f(mid);
        if(tmp < x) hi = mid-1;
        else if(tmp > x) lo = mid+1;
        else hi = mid;
    }
    if(f(lo) != x) lo = hi;
    ans[x] = lo;
    //printf("%lld %d %d\n", lo, f(lo), f(-4));
}

int main(){


    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    for(int i = 0; i < n; i++) id[i] = i;

    sort(id, id+n, [=](int a, int b){ return v[a] < v[b]; });

    sum[0] = v[0];
    for(int i = 1; i < n; i++) sum[i] = sum[i-1] + v[i];

    qwe = Segtree(n);

    for(int i = 0; i < n; i++)
        qwe.update(i, i, sum[i]);

    for(int i = 0; i <= n; i++){
        findlow(i);
        if(ans[i] <= 0){
            for(int j = i; j <= n; j++)
                ans[j] = ans[i];
            break;
        }
    }

    for(int i = n-1; i >= 0; i--){
        if(f(ans[i]) != i) ans[i] = ans[i+1];
        //printf("%lld ", ans[i]);
    }
    for(int i = 0; i < n/2; i++)
        swap(ans[i], ans[n-1-i]);
    //printf("\n");

    //printf("%d\n\n", f(0));
    int w;

    long long b;

    while(m--){
        scanf("%lld", &b);

        w = 0;
        /*for(int i = 0; i < n; i++){
            if(ans[i] > b){
                w = (n-1-i)+1;
                break;
            }
        }*/
        int id = upper_bound(ans, ans + n, b) - ans;
        w = max(0, n-1-id + 1);
        printf("%d\n", w);
    }

    return 0;
}
