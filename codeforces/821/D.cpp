#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 10004;

bitset<N*N> mat;
int n, m, k;

short int dist[N][N][3]; // 0 - non lamp; 1 - row; 2 - collum

int dx[] = {0, 0, 1,-1};
int dy[] = {1,-1, 0, 0};

int bfs(){

    deque<pair<pair<int, int>, int> > q;
    q.push_front(mp(mp(1, 1), 0));

    dist[1][1][0] = 0;

    int x, y, xx, yy, nmode, mode;
    while(!q.empty()){
        x = q.front().ff.ff, y = q.front().ff.ss, mode = q.front().ss;
        if(x == n && y == m) return dist[x][y][mode];
        q.pop_front();

        for(int i = 0; i < 4; i++){
            xx = x + dx[i], yy = y + dy[i];
            if(xx <= 0 || yy <= 0 || xx > n || yy > m) continue;
            if(mat[xx*N+yy]){
                nmode = 0;
                if(mode == 1 && x == xx) nmode = 1;
                else if(mode == 2 && y == yy) nmode = 2;
                if(dist[xx][yy][nmode] > dist[x][y][mode]){
                    dist[xx][yy][nmode] = dist[x][y][mode];
                    q.push_front(mp(mp(xx, yy), nmode));
                }
            }
            else{
                if((mode == 1 && x == xx) || (mode == 2 && y == yy)){
                    if(dist[xx][yy][mode] > dist[x][y][mode]){
                        dist[xx][yy][mode] = dist[x][y][mode];
                        q.push_front(mp(mp(xx, yy), mode));
                    }
                }
                if(mat[x*N+y]){
                    for(nmode = 1; nmode < 3; nmode++)
                    if(dist[xx][yy][nmode] > dist[x][y][mode]+1){
                        dist[xx][yy][nmode] = dist[x][y][mode]+1;
                        q.push_back(mp(mp(xx, yy), nmode));
                    }
                }
                
            }
        }
    }
    return -1;
}

int main(){

    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++)
        for(int k = 0; k < 3; k++)
            dist[i][j][k] = n+m+2;


    for(int i = 0; i < k; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        for(int mode = 0; mode < 3; mode++)
            dist[x][y][mode] = -1;
    }
    printf("%d\n", bfs());

    return 0;
}
