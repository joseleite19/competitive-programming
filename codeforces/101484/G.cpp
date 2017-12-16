#include <bits/stdc++.h>

#define ff first
#define ss second
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define MOD 1000000007LL

using namespace std;
typedef long long ll;

struct matrix{
    int mat[30][30];
    matrix(){ memset(mat, 0, sizeof mat); }
    matrix operator*(const matrix &o) const{
        matrix c;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                c.mat[i][j] = MOD;
                for(int k = 0; k < 26; k++){
                    c.mat[i][j] = min(c.mat[i][j], mat[i][k] + o.mat[k][j]);
                }
            }
        }
        return c;
    }
};

int f(matrix b, int e){
    matrix ans;
    for(int i = 0; i < 26; i++)
        ans.mat[i][i] = 1;

    while(e){
        if(e & 1) ans = ans * b;
        b = b * b;
        e >>= 1;
    }

    int ret = MOD;
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            ret = min(ret, ans.mat[i][j]);

    return ret;
}

int main(){
    int n;

    scanf("%d", &n);

    matrix a;

    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            scanf("%d", &a.mat[i][j]);

    printf("%d\n", f(a, n-1));

    return 0;
}
