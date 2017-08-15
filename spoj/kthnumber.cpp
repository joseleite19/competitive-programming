#include <bits/stdc++.h>

#define ff first
#define ss second

#define oo 1000000007

using namespace std;

class wavelet{
    int n, small, large;
    vector<vector<int> > wt, l, r;

    void build(int p, int L, int R, const vector<int>& v){
        if(R <= L) return;
        wt[p].assign(v.size()+1, 0);
        l[p].assign(v.size()+1, 0);
        r[p].assign(v.size()+1, 0);
        int mid = (L+R)/2;
        vector<int> left, right;
        int c = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] <= mid){
                left.push_back(v[i]);
                c++;
            }
            else{
                right.push_back(v[i]);
            }
            l[p][i+1] = c, r[p][i+1] = i+1-c;
        }
        build(2*p, L, mid, left);
        build(2*p+1, mid+1, R, right);
    }

    int find(int p, int L, int R, int i, int j, int k){
        if(L == R) return L;
        int mid = (L+R)/2;
        int c = l[p][j] - l[p][i-1];
        if(c >= k) return find(2*p, L, mid, l[p][i-1]+1, l[p][j], k);
        else return find(2*p+1, mid+1, R, r[p][i-1]+1, r[p][j], k - c);
    }

public:
    wavelet(vector<int> &v) : n(v.size()), wt(4*v.size()), l(4*v.size()), r(4*v.size()){
        small = oo;
        large =-oo;
        for(int i = 0; i < v.size(); i++)
            small = min(small, v[i]),
            large = max(large, v[i]);
        build(1, small, large, v);
    }
    
    int find(int i, int j, int k){
        return find(1, small, large, i, j, k);
    }
};

int back[100005];

int main(){

    int n, m;

    scanf("%d %d", &n, &m);
    vector<int> v(n);

    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    {
        set<int> s;
        for(int i = 0; i < n; i++) s.insert(v[i]);
        map<int, int> go;
        int ptr = 1;
        for(int x : s) back[ptr] = x, go[x] = ptr++;
        for(int i = 0; i < n; i++) v[i] = go[ v[i] ];
    }

    wavelet wt(v);

    for(int i = 0; i < m; i++){
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", back[wt.find(l, r, k)]);
    }

    return 0;
}
