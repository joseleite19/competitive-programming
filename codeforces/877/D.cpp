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
const int N = 1005;

char s[N][N];
int mat[N][N];

int s1[N][N], s2[N][N];

int n, m, k;
set<int> h[N], v[N];

int main(){

    scanf("%d %d %d", &n, &m, &k);

    forn(i, n) scanf(" %s", s[i]);

    forn(i, n) forn(j, m) mat[i][j] = MOD;

    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d); a--, b--, c--, d--;

    forn(i, n) forn(j, m){
        h[i].insert(-1), v[j].insert(-1), v[j].insert(n), h[i].insert(m);
        if(s[i][j] == '.')
            h[i].insert(j), v[j].insert(i);
        else s1[i][j] = 1, s2[i][j] = 1;
    }

    forn(i, n) forn(j, m)
        s1[i][j+1] += s1[i][j], s2[i+1][j] += s2[i][j];

/*    forn(i, n){
        forn(j, m) printf("%d ", s1[i][j]);
        printf("\n");
    }

    forn(i, n){
        forn(j, m) printf("%d ", s2[i][j]);
        printf("\n");
    }*/
    queue<pair<int, int> > q;
    q.emplace(a, b);
    mat[a][b] = 0;
    h[a].erase(b), v[b].erase(a);

    while(!q.empty()){
        tie(a, b) = q.front(), q.pop();
        //printf("%d %d\n", a, b);
        int x, y;
        x = a, y = b;
        while(1){ // left
            y = *h[a].lower_bound(y);
            if(y > b+k) break;
            if(y == m) break;
            if(s1[a][y] - (b ? s1[a][b-1] : 0)) break;
            //printf("%d\n", h[a].count(y));
            h[a].erase(y);
            //printf("%d\n", h[a].count(y));
            v[y].erase(a);
            mat[a][y] = mat[a][b]+1;
            q.emplace(a, y);
        }
        x = a, y = b;
        while(1){ // right
            y = *prev(h[a].lower_bound(y));
            if(y < b-k) break;
            if(y == -1) break;
            if(s1[a][b] - (y ? s1[a][y-1] : 0)) break;
            h[a].erase(y), v[y].erase(a);
            mat[a][y] = mat[a][b]+1;
            q.emplace(a, y);
        }
        x = a, y = b;
        while(1){ // down
            x = *v[b].lower_bound(x);
            if(x > a+k) break;
            if(x == n) break;
            if(s2[x][b] - (a ? s2[a-1][b] : 0)) break;
            //if(a == 0 && b == 0) printf("asd %d %d, %d %d\n", x, y, y > b+k, y==m);
            h[x].erase(b), v[b].erase(x);
            mat[x][b] = mat[a][b]+1;
            q.emplace(x, b);
        }
        x = a, y = b;
        while(1){ // up
            x = *prev(v[b].lower_bound(x));
            if(x < a-k) break;
            if(x == -1) break;
            if(s2[a][b] - (x ? s2[x-1][b] : 0)) break;
            h[x].erase(b), v[b].erase(x);
            mat[x][b] = mat[a][b]+1;
            q.emplace(x, b);
        }
    }

    if(mat[c][d] == MOD) mat[c][d] = -1;
    printf("%d\n", mat[c][d]);



    return 0;
}
