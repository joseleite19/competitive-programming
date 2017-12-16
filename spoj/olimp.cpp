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
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const int N = 60;
const int oo= 1000000000;

class edge{
    public:
        int to, cost, cap, rev;
        edge(int to = 0, int cost = 0, int cap = 0, int rev = 0) :
            to(to), cost(cost), cap(cap), rev(rev) {}
};

vector<edge> g[N];
int d[N], p[N], id[N];
int n, source, target;

void addEdge(int from, int to, int cost, int cap){
    edge a(to, cost, cap, g[to].size());
    edge b(from, -cost, 0, g[from].size());
    g[from].push_back(a);
    g[to].push_back(b);
}

int back(int s, int minE){
    if(s == source) return minE;

    int f = back(p[s], min(minE, g[ p[s] ][ id[s] ].cap));

    g[ p[s] ][ id[s] ].cap -= f;
    g[s][ g[ p[s] ][ id[s] ].rev ].cap += f;
    return f;
}

int dijkstra(){
    for(int i = 0; i < N; i++) d[i] = oo;
    d[source] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push({0, source});
    while(!pq.empty()){
        int u = pq.top().second;
        int r = -pq.top().first; pq.pop();
        if(r > d[u]) continue;
        for(int i = 0; i < g[u].size(); i++){
            auto x = g[u][i];
            if(!x.cap) continue;
            int w = r + x.cost;
            int v = x.to;
            if(w < d[v]){
                id[v] = i, p[v] = u, d[v] = w;
                pq.push({-w, v});
            }
        }
    }

    return d[target] != oo;
}

vector<int> mincost(){ // return <min cost, max flow>
    vector<int> v;
    while(dijkstra()){
        int f = back(target, oo);
        while(f--) v.pb(d[target]);
    }
    return move(v);
}


int main(){
    int n, m, k;

    for(int tc = 1; scanf("%d %d %d", &n, &m, &k) == 3 && n+m+k; tc++){
        forn(i, N) g[i].clear();

        int a, b, c;
        forn(i, m){
            scanf("%d %d %d", &a, &b, &c);
            addEdge(a, b, 1, c);
        }
        source = 1, target = n;

        vector<int> v = mincost();

        forn(i, v.size()) printf(".%d.\n", v[i]);
        int ans = 0;

        multiset<int> s;

        forn(i, k) s.insert(v[0]++);

        forn(i, v.size()){
            while(*prev(s.end()) > v[i]){
                s.erase(prev(s.end()));
                s.insert(v[i]++);
            }
        }

        ans = *prev(s.end());

        printf("%d\n", ans);
    }

    return 0;
}
