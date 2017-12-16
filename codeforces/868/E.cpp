#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
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
typedef pair<int, int> pi;
const ll oo = 1000000000000000000;
const int N = 55;

vector<pi> g[N];
int leaf[N];
int d[N][N];

vector<pi> dfs(int u, int p, int s){
    leaf[u] = 1;
    vector<pi> ret, t;

    for(auto x : g[u]) if(x.ff != p){
        leaf[u] = 0;
        t = dfs(x.ff, u, s);
        forn(i, t.size()) ret.eb(t[i].ff + x.ss, t[i].ss);
    }
    if(leaf[u] && u != s) ret.eb(0, u);
    return move(ret);
}

int n;
int sp[N];

int f(int u, int qnt){
    if(qnt == 0) return 0;

    vector<pi> tmp = dfs(u, u, u);
    sort(tmp.begin(), tmp.end()); reverse(tmp.begin(), tmp.end());

    int k = (qnt + tmp.size() - 1)/ tmp.size();




}



int main(){

    scanf("%d", &n);

    forn(i, n-1){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[a].eb(b, c);
        g[b].eb(a, c);
    }

    int s, m;

    scanf("%d %d", &s, &m);

    while(m--){
        int x;
        scanf("%d", &x);
        sp[x]++;
    }




    return 0;
}
