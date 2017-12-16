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

int v[N];
int dp[N][2];
int n;

int f(int i, int p){
    if(i == n) return p == 0;

    int &ans = dp[i][p];
    if(~ans) return ans;
    ans = f(i+1, (p*v[i])&1);
    ans += f(i+1, (p*(v[i]-1))&1);
    ans += f(i+1, (p*(v[i]+1))&1);
    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);

    scanf("%d", &n);

    forn(i, n) scanf("%d", v+i);

    printf("%d\n", f(0, 1));


    return 0;
}
