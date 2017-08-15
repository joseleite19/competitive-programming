#include <bits/stdc++.h>

using namespace std;

const int N = 50004;

int p[N];

class MergeSortTree{
    int n;
    vector<vector<int> > v;

    void build(int p, int L, int R, const vector<int> &vet){
        for(int i = L; i <= R; i++)
            v[p].push_back(vet[i-1]);
        sort(v[p].begin(), v[p].end());
        if(L == R) return;
        int mid = (L+R)/2;
        build(2*p, L, mid, vet);
        build(2*p+1, mid+1, R, vet);
    }

    int count_leq(int p, int L, int R, int i, int j, int x) const{
        if(i > R || j < L) return 0;
        if(L >= i && R <= j){
            int id = lower_bound(v[p].begin(), v[p].end(), x) - v[p].begin();
            if(id == v.size()) return v.size();
            if(v[p][id] > x) return id;
            return id+1;
        }
        int mid = (L+R)/2;
        return count_leq(2*p, L, mid, i, j, x) +
            count_leq(2*p+1, mid+1, R, i, j, x);
    }

public:
    MergeSortTree(int sz, const vector<int> &vet) : n(sz), v(4*sz){
        build(1, 1, n, vet);
    }
    int count_leq(int i, int j, int x) const{
        return count_leq(1, 1, n, i, j, x);
    }
};

int mn[N];

int dfs(int u){
    if(mn[u]) return mn[u];
    mn[u] = u;
    return mn[u] = min(mn[u], dfs(p[u]));
}

int n;

int findmn(int i, int j, const MergeSortTree &mt){
    int L = 1, R = n+1;
    int len = j - i + 1;
    while(L+1 < R){
        int mid = (L+R)/2;
        int cnt = mt.count_leq(i, j, mid);
        if(2*cnt <= len) L = mid;
        else R = mid-1;
    }
    //printf("--%d %d\n", L, R);
    if(2*mt.count_leq(i, j, R) >= len) R = L;
    //printf("--%d %d : %d %d\n", L, R, mt.count_leq(i, j, R), len);
    return R;
}

int findmx(int i, int j, const MergeSortTree &mt){
    int L = 1, R = n+1;
    int len = j - i + 1;
    while(L < R){
        int mid = (L+R)/2;
        int cnt = mt.count_leq(i, j, mid);
        if(2*cnt >= len) R = mid;
        else L = mid+1;
    }
    return L;
}

int findright(int i, int j, const MergeSortTree &mt, int x){
    x = mt.count_leq(i, j, x);
    int L = 1, R = n+1;
    while(L+1 < R){
        int mid = (L+R)/2;
        int cnt = mt.count_leq(i, j, mid);
        if(cnt < x) L = mid+1;
        else if(cnt > x) R = mid-1;
        else R = mid;
    }
    if(mt.count_leq(i, j, L) != x) L = R;
    return L;
}

int main(){

    int q;

    scanf("%d %d", &n, &q);

    for(int i = 1; i <= n; i++)
        scanf("%d", p+i);

    for(int i = 1; i <= n; i++)
        dfs(i);

    /*for(int i = 1; i <= n; i++)
        printf("%d ", mn[i]);
    printf("\n");*/

    vector<int> tmp;
    for(int i = 1; i <= n; i++)
        tmp.push_back(mn[i]);
    MergeSortTree mt(n, tmp);

    while(q--){
        int a, b;
        scanf("%d %d", &a, &b);
        int x = findmn(a, b, mt);
        int y = findmx(a, b, mt);
        int len = b - a + 1;
        //printf("%d %d\n", x, y);
        if(abs(x - len/2) <= abs(y - len/2)) x = x;
        else x = y;
        x = findright(a, b, mt, x);
        printf("%d\n", x);
    }


    return 0;
}
