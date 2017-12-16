#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < int(n); ++i)

#define MOD 13

using namespace std;

int add(int a, int b){
    return a + b >= MOD ? a + b - MOD : a + b;
}

int mul(int a, int b){
    return (a * b) % MOD;
}

struct matrix{
    int n;
    vector<vector<int> > mat;
    matrix(int sz = 0) : n(sz), mat(sz, vector<int>(sz, 0)) {}
    matrix operator*(const matrix &o) const{
        matrix ans(n);
        forn(i, n) forn(j, n) forn(k, n){
            ans.mat[i][j] = add(ans.mat[i][j], mul(mat[i][k], o.mat[k][j]));
        }  
        return ans;
    }
};

matrix f(matrix a, long long k){
    matrix ans(a.mat.size());
    forn(i, ans.mat.size()) ans.mat[i][i] = 1;
    while(k){
        if(k & 1) ans = ans * a;
        a = a * a;
        k >>= 1;
    }
    return ans;
}

int main(){

    int n;
    long long k;

    scanf("%d %lld", &n, &k);

    matrix w(n);

    forn(i, n) forn(j, n)
        scanf("%d", &w.mat[i][j]);

    w = f(w, k);

    forn(i, n){
        forn(j, n) printf(" %d", w.mat[i][j]);
        printf("\n");
    }

	return 0;
}
