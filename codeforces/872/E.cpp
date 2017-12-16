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

int n, x[N], y[N];
ll p[N], p1[N];

map<int, set<int> > xx, yy;

int main(){

    p[0] = 1, p1[0] = 0;
    for1(i, N-1)
        p[i] = (2*p[i-1]) % MOD, p1[i] = (p[i] - 1 + MOD) % MOD;


    scanf("%d", &n);


    forn(i, n) scanf("%d %d", x+i, y+i), xx[ x[i] ].insert(i), yy[ y[i] ].insert(i);


    ll ans = 1;
    forn(i, n){
        if(!xx[ x[i] ].count(i)) continue;

        queue<int> q;
        set<int> sx, sy, si;
        sx.insert(x[i]);
        sy.insert(y[i]);
        for(int w : xx[ x[i] ]) q.push(w), si.insert(w);
        for(int w : yy[ y[i] ]) q.push(w), si.insert(w);
        xx[ x[i] ].clear(), yy[ y[i] ].clear();

        while(!q.empty()){
            int u = q.front(); q.pop();
            sx.insert(x[u]);
            sy.insert(y[u]);
            for(int w : xx[ x[u] ]) q.push(w), si.insert(w);
            for(int w : yy[ y[u] ]) q.push(w), si.insert(w);
            xx[ x[u] ].clear(), yy[ y[u] ].clear();
        }
        int lines = sx.size() + sy.size();
        int points= si.size();
        if(points == lines-1) ans = (ans * p1[lines]) % MOD;
        else ans = (ans * p[lines]) % MOD;
    }

    printf("%lld\n", ans);



    return 0;
}
