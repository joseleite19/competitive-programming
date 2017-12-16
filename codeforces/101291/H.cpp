#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000007LL
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 105;

char s[N][N];
int n, m;
int vis[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y){
    vis[x][y] = 1;
    forn(i, 4){
        int xx = x + dx[i], yy = y + dy[i];
        if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
        if(vis[xx][yy]) continue;
        if(s[xx][yy] == 'W') continue;
        dfs(xx, yy);
    }

}

int main(){

    scanf("%d %d", &n, &m);

    forn(i, n) scanf(" %s", s[i]);

    int ans = 0;
    forn(i, n) forn(j, m) if(s[i][j] == 'L'){
        if(vis[i][j]) continue;
        ans++;
        dfs(i, j);
    }

    printf("%d\n", ans);



    return 0;
}
