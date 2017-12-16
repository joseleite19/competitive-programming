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
const int N = 555;

int p[N][N], b[N][N];
int n;

inline int fp(int x1, int y1, int x2, int y2){
    return p[x2][y2] - p[x2][y1-1] - p[x1-1][y2] + p[x1-1][y1-1];
}
inline int fb(int x1, int y1, int x2, int y2){
    return b[x2][y2] - b[x2][y1-1] - b[x1-1][y2] + b[x1-1][y1-1];
}

int main(){

    int m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        p[x][y]++;
    }

    for(int i = 0; i < m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        b[x][y]++;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1],
            b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];


    int q = 0, w = 0, t, y;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 0; i + k <= n && j + k <= n; k++){
                t = fp(i, j, i+k, j+k), y = fb(i, j, i+k, j+k);
                if(t && !y) q++;
                if(!t && y) w++;
            }
        }
    }

    printf("%d %d\n", q, w);



    return 0;
}
