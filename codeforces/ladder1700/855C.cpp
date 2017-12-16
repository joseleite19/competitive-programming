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

vector<int> g[N];
int n, m, k, x;

// 0 = less than k
// 1 = equal to k
// 2 = greater than k

ll f(int u, int p, int b, int l){

    ll ans = 1, t;
    bool leaf = true;
    if(b == 1){
        for(int v : g[u]) if(v != p){
            leaf = false;
            t = f(v, u, 0, l) * (k - 1);
            ans *= t;
        }
    }
    if(b == 0){
        for(int v : g[u]) if(v != p){
            leaf = false;
            t = f(v, u, 0, l) * (k - 1);
            if(l) t += f(v, u, 1, l-1);
            t += f(v, u, 2, l) * (m - k);
            ans *= t;
        }
    }
    if(b == 2){
        for(int v : g[u]) if(v != p){
            leaf = false;
            ans *= f(v, u, 0, l) * (k - 1) + f(v, u, 2, l) * (m - k);
            if(u == 1) printf("..%lld %d\n", ans, v);
        }
    }
    if(leaf) ans = 1;
    return ans;
}

int main(){

    scanf("%d %d", &n, &m);

    forn(i, n-1){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].pb(b), g[b].pb(a);
    }

    scanf("%d %d", &k, &x);


    debug(f(1, 1, 1, x-1));
    if(k > 1) debug(f(1, 1, 0, x)*(k-1));
    if(k < m) debug(f(1, 1, 2, x)*(m-k));

    //ll ans = f(1, 1, 0, x-1) + f(1, 1, 1, x) + f(1, 1, 2, x);

    //printf("%lld\n", ans);


    return 0;
}
