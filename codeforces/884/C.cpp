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

int n, p[N], vis[N];

int dfs(int u, int s){
    vis[u] = 1;
    if(u == s) return 1;
    return 1 + dfs(p[u], s);
}

int main(){

    scanf("%d", &n);

    for1(i, n) scanf("%d", p+i);

    vector<int> ans;
    for1(i, n) if(!vis[i]){
        ans.pb(dfs(p[i], i));
    }
    sort(ans.begin(), ans.end());

    if(ans.size() >= 2){
        int x = ans.back(); ans.pop_back();
        ans.back() += x;
    }

    ll sum = 0;
    for(int x : ans) sum += 1LL*x*x;

    printf("%lld\n", sum);



    return 0;
}
