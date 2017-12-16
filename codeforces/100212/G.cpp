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

const ll oo = 100000000000000000;
const int N = 10000006;

void file(){
    freopen("ssh.in", "r", stdin);
    freopen("ssh.out", "w", stdout);
}

int v[200];
int mat[100][100];

int l, m;

int memo [200][100];
int path [200][100];

int f(int i, int c){
    if (memo[i][c] != -1) return memo[i][c];

    if (i == l) return 0;

    int res = 2e9;

    for (int j = 1; j <= m; j++) {
        if (res > abs(mat[c][j] - v[i]) + f(i + 1, j)) {
            res = abs(mat[c][j] - v[i]) + f(i + 1, j);
            path[i][c] = j;
        }
    }
    return memo[i][c] = res;
}


int main(){

        file();

    scanf("%d %d", &l, &m);

    for (int i = 1; i < l; i++) {
        scanf("%d", &v[i]);
    }
    v[0] = 0;

    for (int i = 1; i <= m; i++) {
        mat[0][i] = 0;
        for (int j = 1; j <= m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i <= l; i++) {
        for (int j = 0; j <= m; j++) {
            memo[i][j] = -1;
        }
    }

    f(0, 0);

    int j = 0;
    for (int i = 0; i < l; i++) {
        printf("%c", path[i][j] + 'a' - 1);
        j = path[i][j];
    }
    printf("\n");

    return 0;
}
