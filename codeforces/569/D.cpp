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
const int N = 4005;

inline ll add(ll a, ll b){
    return (a + b >= MOD ? a + b - MOD : a + b);
}

ll C[N][N];

ll ans[N];

int main(){

    C[0][0] = 1;

    for(int i = 1; i < N; i++){
        C[i][0] = C[i-1][i-1];
        for(int j = 1; j <= i; j++)
            C[i][j] = add(C[i][j-1], C[i-1][j-1]);
        ans[i] = add(C[i][i], MOD - C[i-1][i-1]);
    }

    int n;

    scanf("%d", &n);

    printf("%lld\n", ans[n]);

    return 0;
}
