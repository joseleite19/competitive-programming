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
const int N = 2006;

void file(){
    freopen("codes.in", "r", stdin);
    freopen("codes.out", "w", stdout);
}

ll v[N], ft[N], dp[N][N];
int n, sz, opt[N][N];
char ans[100*N];

ll g(){

    for(int j = 1; j <= n; j++){
        dp[j][j] = 0; // base case
        opt[j][j] = j;
        for(int i = j-1; i >= 1; i--){
            int L = max(opt[i][j-1], i), R = min(j-1, opt[i+1][j]);
            
            dp[i][j] = oo;
            fore(k, L, R){
                ll t = ft[j] - ft[i-1] + dp[i][k] + dp[k+1][j];
                if(dp[i][j] > t){
                    dp[i][j] = t;
                    opt[i][j] = k;
                }
            }
        }
    }
}

void pa(int i, int j){
    if(i == j) printf("%s\n", ans);
    else{
        ans[sz++] = '0';
        pa(i, opt[i][j]);
        ans[sz--] = 0;

        ans[sz++] = '1';
        pa(opt[i][j]+1, j);
        ans[sz--] = 0;
    }
}

int main(){

    file();

    scanf("%d", &n);

    for1(i, n) scanf("%lld", v+i);

    for1(i, n) ft[i] = v[i] + ft[i-1];

    g();

    pa(1, n);

    return 0;
}
