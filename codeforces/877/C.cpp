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

map<vector<int>, int> dp;
int f(vector<int> v){
    if(dp.count(v)) return dp[v];
    int t = 0;
    forn(i, v.size()) t += v[i];
    if(!t) return 0;

    int ans = MOD;
    forn(i, v.size()) if(v[i]){
        vector<int> t = v;
        t[i] = 0;
        if(v[i] & 1){
            if(i) t[i-1] |= 2;
            if(i < v.size()) t[i+1] |= 2;
        }
        ans = min(ans, f(t));
    }
    return dp[v] = ans+1;
}

int v[N];

int main(){

    int n;

    scanf("%d", &n);

    for1(i, n) v[i] = 1;

    vector<int> ans;

    for(int i = 2; i <= n; i += 2){
        ans.pb(i);
        v[i] &= ~1;
        if(i < n) v[i+1] |= 2;
        if(i > 1) v[i-1] |= 2;
    }

    for(int i = 1; i <= n; i += 2) if(v[i] & 1){
        ans.pb(i);
        v[i] = 0;
        if(i < n) v[i+1] |= 2;
        if(i > 1) v[i-1] |= 2;
    }

    for(int i = 1; i <= n; i++) if(v[i])
        ans.pb(i);

    printf("%d\n", int(ans.size()));
    forn(i, ans.size()) printf("%d ", ans[i]); printf("\n");


    return 0;
}
