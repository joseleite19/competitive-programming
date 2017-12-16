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
const int N = 505;

int n;

int mat[N][N];

vector<tuple<int, int, int>> q;

int m, k, Q;
bool f(int t){
    memset(mat, 0, sizeof mat);

    for(int i = 0; i < q.size(); i++){
        int w, x, y;
        tie(w, x, y) = q[i];
        if(w > t) break;
        mat[x][y] = 1;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];

    for(int i = 1; i <= n - k + 1; i++){
        for(int j = 1; j <= m - k + 1; j++){
            int tmp = mat[i+k-1][j+k-1] - mat[i+k-1][j-1] - mat[i-1][j+k-1] + mat[i-1][j-1];
            if(tmp == k*k) return 1;
        }
    }

    return 0;
}

int main(){
    
    scanf("%d %d %d %d", &n, &m, &k, &Q);

    for(int i = 0; i < Q; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        q.eb(c, a, b);
    }

    sort(q.begin(), q.end());

    int lo = 0, hi = 1000000001;

    while(lo < hi){
        int mid = (lo + hi) / 2;

        if(f(mid)) hi = mid;
        else lo = mid+1;
    }

    if(lo == 1000000001) lo = -1;

    printf("%d\n", lo);

    return 0;
}
