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

int n, m, k;

int mat[N][N];
int pre[N];

pair<int, int> f(int j){
    for1(i, n) pre[i] = pre[i-1] + mat[i][j];

    int ans = 0, t = 0, q = 0;
    for1(i, n){
        if(mat[i][j]){
            int w = min(n, i + k - 1);
            int e = pre[w] - pre[i-1];
            if(e > ans){
                ans = e, t = q;
            }

            q++;
        }
    }
    return mp(ans, t);
}

int main(){

    scanf("%d %d %d", &n, &m, &k);

    for1(i, n) for1(j, m)
        scanf("%d", &mat[i][j]);

    pair<int, int> ans = mp(0, 0);

    for1(j, m){
        pair<int, int> ret = f(j);
        ans.ff += ret.ff, ans.ss += ret.ss;
    }

    printf("%d %d\n", ans.ff, ans.ss);



    return 0;
}
