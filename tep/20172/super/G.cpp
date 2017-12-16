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
const int N = 50005;

double mat[2][N];

double v[N];
int n;

vector<pair<int, vector<double> > > w[N];

double ans[N];

int main(){

    int T;
    scanf("%d", &T);

    int lim = 0;
    for1(tc, T){
        scanf("%d", &n);

        vector<double> v(n);
        forn(i, n) scanf("%lf", &v[i]);
        w[n-1].eb(tc, move(v));
        lim = max(n, lim);
    }

    mat[0][0] = 1;

    for(auto &x : w[0]){
        int id = x.ff, j = 0;
        for(double q : x.ss) ans[id] += mat[0][j++] * q;
    }

    for1(i, lim){
        int c = i & 1;
        mat[c][0] = mat[c^1][0]*0.5;
        for1(j, i)
            mat[c][j] = (mat[c^1][j-1] + mat[c^1][j]) * 0.5;

        for(auto &x : w[i]){
            int id = x.ff, j = 0;
            for(double q : x.ss) ans[id] += mat[c][j++] * q;
        }
    }

    for1(tc, T) printf("Case #%d: %.3lf\n", tc, ans[tc]);

    return 0;
}
