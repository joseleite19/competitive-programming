#include <bits/stdc++.h>

using namespace std;

const int N = 6005;
const int oo= 1000000000;

class edge{
    public:
        int to, cost, cap, rev;
        edge(int to = 0, int cost = 0, int cap = 0, int rev = 0) :
            to(to), cost(cost), cap(cap), rev(rev) {}
};

vector<edge> g[2*N];
int d[2*N], p[2*N], id[2*N];
int n, source = 0, target = 2*N-1;

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
    for(int i = 0; i < 2*N; i++) d[i] = oo;
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
                id[v] = i;
                p[v] = u;
                d[v] = w;
                pq.push({-w, v});
            }
        }
    }

    return d[target] != oo;
}

pair<int, int> mincost(){ // return <min cost, max flow>
    int mf = 0, ans = 0;
    while(dijkstra()){
        int f = back(target, oo);
        mf += f;
        ans += 1LL * f * d[target];
    }
    return {ans, mf};
}

int main(){

    int prog, sport;
    scanf("%d %d %d", &n, &prog, &sport);

    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        addEdge(source, i, 0, 1);
        addEdge(i, N+i, x, 1);
        addEdge(N+i, target-2, 0, 1);
    }

    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        addEdge(i, N+N+i, x, 1);
        addEdge(N+N+i, target-1, 0, 1);
    }

    addEdge(target-2, target, 0, prog);
    addEdge(target-1, target, 0, sport);

    printf("%d\n", mincost().second);

    return 0;
}

