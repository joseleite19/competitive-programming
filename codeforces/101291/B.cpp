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
const int N = 100005;

char mat[55][55];
int dp[55][55][55];
char commands[55];
pair<int,int> st, ed;
int n,m;
int r[4] = {0,1,0,-1};
int c[4] = {1,0,-1,0};
map<char, pair<int,int> > tab;

int main(){
    tab['D'] = mp(1,0); 
    tab['R'] = mp(0,1); 
    tab['U'] = mp(-1,0); 
    tab['L'] = mp(0,-1); 

    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; ++i) {
        scanf(" %s", mat[i]);
        for(int j = 0; j < m; j++)
            if(mat[i][j] == 'R') st = mp(i,j);
            else if(mat[i][j] == 'E') ed = mp(i,j);
    }

    scanf(" %s", commands);
    int tam = strlen(commands);

    memset(dp, 0x3f, sizeof dp);

    queue<pair<pair<int,int>, int>> Q;

    dp[st.ff][st.ss][0] = 0;
    Q.push(mp(st,0));

    while(!Q.empty()) {
        pair<int,int> v = Q.front().ff;
        int pos = Q.front().ss; Q.pop();
        
        
        if(pos < tam) {
            pair<int,int> step = tab[commands[pos]];
            pair<int,int> w = mp(step.ff + v.ff, step.ss + v.ss);
            if(!(w.ff < 0 or w.ff >= n or w.ss < 0 or w.ss >= m or mat[w.ff][w.ss] == '#')) {
                if(dp[w.ff][w.ss][pos+1] > dp[v.ff][v.ss][pos]) {
                    dp[w.ff][w.ss][pos+1] = dp[v.ff][v.ss][pos];
                    Q.push(mp(w,pos+1));
                }
            }
            else {
                if(dp[v.ff][v.ss][pos+1] > dp[v.ff][v.ss][pos]) {
                    dp[v.ff][v.ss][pos+1] = dp[v.ff][v.ss][pos];
                    Q.push(mp(v,pos+1));
                }
            }
        }

        for(int i = 0; i < 4; i++) {
            int x = c[i]+v.ff;
            int y = r[i]+v.ss;
            if(!(x < 0 or x >= n or y < 0 or y >= m or mat[x][y] == '#')) {
                if(dp[x][y][pos] > dp[v.ff][v.ss][pos] + 1) {
                    dp[x][y][pos] = dp[v.ff][v.ss][pos] + 1;
                    Q.push(mp(mp(x,y),pos));
                }
            }
        }

    }

    int ans = 1e9;
    for(int i = 0; i <= tam; i++) {
        ans = min(ans, dp[ed.ff][ed.ss][i]);
    }

    printf("%d\n", ans);

    return 0;
}
