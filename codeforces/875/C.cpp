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

vector<int> v[N];
int forb[N], cap[N];

int ptr = 1;
map<int, int> tr[2*N];
vector<int> tc[2*N];
set<int> ans;

void add(const vector<int> &v){
    int p = 0;
    forn(i, v.size()){
        tc[p].pb(v[i]);
        if(!tr[p].count(v[i])) tr[p][ v[i] ] = ptr++;
        p = tr[p][ v[i] ];
    }
}

int main(){

    int n, m;

    scanf("%d %d", &n, &m);

    set<int> id;
    forn(i, n){
        id.insert(i);
        int sz;
        scanf("%d", &sz);
        v[i].assign(sz, 0);
        forn(j, sz) scanf("%d", &v[i][j]);
    }

    for1(i, n-1){ // check if i is preffix of i-1
        if(v[i].size() >= v[i-1].size()) continue;
        bool eq = 1;
        forn(j, v[i].size()) if(v[i][j] != v[i-1][j]){
            eq = 0;
            break;
        }
        if(eq) return printf("No\n"), 0;
    }

    ford(i, n) add(v[i]);

    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int u = q.front(); q.pop();
        int last = -1;
        for(int x : tc[u]){
            if(last == -1){ last = x; continue; }
            if(x == last) continue;
            if(cap[last] && !cap[x]){
                if(forb[x]) return printf("No\n"), 0;
                cap[x] = 1;
                ans.insert(x);
            }
            else if(cap[last] && cap[x]){
                if(last < x) return printf("No\n"), 0;
            }
            else if(!cap[last] && cap[x]){}
            else if(!cap[last] && !cap[x]){
                if(last < x){
                    if(forb[x]) return printf("No\n"), 0;
                    cap[x] = 1;
                    ans.insert(x);
                }
            }
            forb[last] = 1;
            last = x;
        }

        for(auto x : tr[u]) q.push(x.ss);
    }

    printf("Yes\n");

    printf("%d\n", int(ans.size()));

    for(int x : ans) printf("%d ", x);
    printf("\n");

    return 0;
}
