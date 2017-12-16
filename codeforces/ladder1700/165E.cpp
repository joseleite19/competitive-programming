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
const int N = 1000006;

int n, v[N], vis[5*N];
int dp[5*N];

int f(int x){
    if(vis[x]) return x;
    int &ans = dp[x];
    if(~ans) return ans;

    ans = 0;
    forn(i, 22) if(x & (1 << i)){
        ans = f(x - (1 << i));
        if(ans) break;
    }
    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);

    scanf("%d", &n);

    forn(i, n) scanf("%d", v+i), vis[ v[i] ] = 1;


    int t, tmp = (1 << 22) - 1;
    forn(i, n) t = tmp & ~v[i], printf("%d%c", f(t) ? f(t) : -1, " \n"[i == n-1]);


    return 0;
}
