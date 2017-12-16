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
const int N = 105;

int mat[N][N];

int n, m;

bool inter(int a, int b, int c, int d){
    if(a > b) swap(a, b);
    if(c > d) swap(c, d);
    return max(a, c) <= min(b, d);
}

int d(int x){
    if(x > 0) return  1;
    if(x < 0) return -1;
    return 0;
}

bool vert(int i, int j){
    if(d(mat[i][j] - mat[i][j-1]) != d(mat[i-1][j] - mat[i-1][j-1]))
        return 1;

    return !inter(mat[i][j], mat[i][j-1], mat[i-1][j], mat[i-1][j-1]);
}

bool hor(int i, int j){
    if(d(mat[i][j] - mat[i-1][j]) != d(mat[i][j-1] - mat[i-1][j-1]))
        return 1;
    return !inter(mat[i][j], mat[i-1][j], mat[i][j-1], mat[i-1][j-1]);
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int vis[N][N];

void dfs(int x, int y){
    vis[x][y] = 1;

    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
        if(mat[x][y] != mat[xx][yy] || vis[xx][yy]) continue;
        dfs(xx, yy);
    }
}

int main(){

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);

    int ans = 5;

    for(int j = 1; j < m; j++)
        ans += mat[0][j] != mat[0][j-1];
    
    for(int i = 1; i < n; i++)
        ans += mat[i][0] != mat[i-1][0];

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(mat[i][j] != mat[i][j-1]){
                ans += vert(i, j);
            }
            if(mat[i][j] != mat[i-1][j]){
                ans += hor(i, j);
            }
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) if(!vis[i][j])
            ans++, dfs(i, j);

    printf("%d\n", ans);


    return 0;
}
