#include <bits/stdc++.h>

#define ff first
#define ss second
#define oo 1000000000000000000

using namespace std;

typedef long long ll;

const int N = 30005;

class Segtree{
    int n;
    vector<ll> st, lz, cnt, mx;

    void push(int p, int L, int R){
        if(lz[p]){
            st[p] += lz[p];
            if(L != R) lz[2*p] += lz[p], lz[2*p+1] += lz[p];
            lz[p] = 0;
            if(st[p] == mx){
                cnt[p];
            }
        }
        if(st[p] > mx){
            mx = st[p];
        }
    }

    void update(int p, int L, int R, int i, int j, long long v){
        push(p, L, R);
        if(L > j || R < i) return;
        if(L >= i && R <= j){
            lz[p] = v;
            push(p, L, R);
            return;
        }
        int mid = (L+R)/2;
        update(2*p, L, mid, i, j, v);
        update(2*p+1, mid+1, R, i, j, v);
        st[p] = max(st[2*p], st[2*p+1]);
    }

    long long query(int p, int L, int R, int i, int j){
        push(p, L, R);
        if(L > j || R < i) return -oo;
        if(L >= i && R <= j) return st[p];
        int mid = (L+R)/2;
        return max(query(2*p, L, mid, i, j),
                  query(2*p+1, mid+1, R, i, j));
    }

    int erase(int p, int L, int R, long long val){
        push(p, L, R);
        if(st[p] <= val) return 0;
        if(L == R){
            st[p] = -oo;
            return 1;
        }
        int mid = (L+R)/2;
        int ret = 0;
        ret += erase(2*p, L, mid, val);
        ret += erase(2*p+1, mid+1, R, val);
        st[p] = max(st[2*p], st[2*p+1]);
        return ret;
    }
    
    int simul(int p, int L, int R, long long val){
        push(p, L, R);
        return cnt[p];
    }


public:
    Segtree(int sz = 0) : n(sz), st(4*sz, 0), lz(4*sz, 0), cnt(4*sz, 0) {}

    void update(int i, int j, long long v){
        update(1, 1, n, i, j, v);
    }
    long long query(int i, int j){
        return query(1, 1, n, i, j);
    }
    int simul(long long val){ return simul(1, 1, n); }

    int erase(long long val){ return erase(1, 1, n, val); }
};

void file(){
    freopen("f.in", "r", stdin);
}

int main(){
    file();

    int n, k;

    while(scanf("%d %d", &n, &k) == 2 && n+k){
        Segtree st(n);

        vector<int> tmp(n, 0);
        for(int i = 0; i < n; i++){
            scanf("%d", &tmp[i]);
            st.update(i+1, i+1, tmp[i]);
        }
        sort(tmp.begin(), tmp.end());
        int sz = n - st.erase(tmp[n/2]);

        int a, b, old = st.query(1, n);
        while(k--){
            scanf("%d %d", &a, &b);
            st.update(a, b, 1);

            while(sz > (n+1)/2){
                if(sz - st.simul(st.query(1, n)) >= (n+1)/2){
                    sz -= st.erase(st.query(1, n));
                }
                else break;
            }

            printf("%lld\n", st.query(1, n));

            old = st.query(1, n);
        }
    }


    return 0;
}
