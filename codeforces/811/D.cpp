#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 333;
char mat[N][N];
int n, m;
int path[N*N];
pair<int, int> pi[N][N];
int dist[N][N];

int dx[] = {0, 0,-1, 1};
int dy[] = {1,-1, 0, 0};

int t;
void back(pair<int, int> q){
    if(q.ff == 0 && q.ss == 0) return;
    back(pi[q.ff][q.ss]);
    pair<int, int> w = pi[q.ff][q.ss];
    if(q.ff - w.ff == 1) path[t++] = 1;
    if(q.ff - w.ff ==-1) path[t++] = 2;
    if(q.ss - w.ss == 1) path[t++] = 3;
    if(q.ss - w.ss ==-1) path[t++] = 4;
}

void bfs(){
    memset(pi, -1, sizeof pi);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
        dist[i][j] = 10*N*N;
    dist[0][0] = 0;

    queue<pair<int, int> > q;
    q.push(mp(0, 0));

    int xf, yf;

    while(!q.empty()){
        int x = q.front().ff, y = q.front().ss; q.pop();

        if(mat[x][y] == 'F') xf = x, yf = y;

        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            if(mat[xx][yy] == '*') continue;
            if(dist[xx][yy] > dist[x][y]+1){
                dist[xx][yy] = dist[x][y]+1;
                pi[xx][yy] = mp(x, y);
                q.push(mp(xx, yy));
            }
        }
    }
    back(mp(xf, yf));
}
pair<int, int> play(char c){
    pair<int, int> ret;
    printf("%c\n", c); fflush(stdout);
    scanf("%d %d", &ret.ff, &ret.ss); ret.ff--, ret.ss--;
    return ret;
}

int main(){

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf(" %s", mat[i]);

    bfs();

    int x = 0, y = 0;
    int cx = 0, cy = 0;
    int a, b;
    char u = 'U', d = 'D', l = 'L', r = 'R';
    int ptr = 0;
    // for(int i = 0; i < t; i++) printf("%d", path[i]);
    while(1){

        if(!cx){
            if(y < m && mat[x][y+1] != '*'){
                pair<int, int> tmp = play('R');
                a = tmp.ff, b = tmp.ss;
                if(a == x && b == y) swap(r, l);
                cx = 1;
                if(mat[a][b] == 'F') return 0;
                if(a != x || b != y) play('L');
            }
            if(!cx && y-1 >= 0 && mat[x][y-1] != '*'){
                pair<int, int> tmp = play('L');
                a = tmp.ff, b = tmp.ss;
                if(a == x && b == y) swap(r, l);
                cx = 1;
                if(mat[a][b] == 'F') return 0;
                if(a != x || b != y) play('L');
            }
        }
        if(!cy){
            if(x+1 < n && mat[x+1][y] != '*'){
                pair<int, int> tmp = play('D');
                a = tmp.ff, b = tmp.ss;
                if(a == x && b == y) swap(d, u);
                cy = 1;
                if(mat[a][b] == 'F') return 0;
                if(a != x || b != y) play('U');
            }
            if(!cy && x-1 >= 0 && mat[x-1][y] != '*'){
                pair<int, int> tmp = play('U');
                a = tmp.ff, b = tmp.ss;
                if(a == x && b == y) swap(d, u);
                cy = 1;
                if(mat[a][b] == 'F') return 0;
                if(a != x || b != y) play('D');
            }
        }

        if(path[ptr] == 1) tie(x, y) = play(d);
        if(path[ptr] == 2) tie(x, y) = play(u);
        if(path[ptr] == 3) tie(x, y) = play(r);
        if(path[ptr] == 4) tie(x, y) = play(l);
        ptr++;
        if(mat[x][y] == 'F') break;
    
    }






    return 0;
}
