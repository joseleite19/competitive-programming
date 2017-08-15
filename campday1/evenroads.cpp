#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 100000000000000000

using namespace std;

const int N = 100005;

vector<pair<int, long long> > g[N];

long long dist[N][2];

int n, m;

long long dijkstra(){
    for(int i = 1; i <= n; i++) dist[i][0] = dist[i][1] = oo;

    dist[1][0] = 0;
    priority_queue<pair<pair<long long, int>, int> > pq; // <<dist, u>, p>
    pq.push(mp(mp(0, 1), 0));
    
    while(!pq.empty()){
        int u = pq.top().ff.ss;
        long long d = -pq.top().ff.ff;
        int p = pq.top().ss; pq.pop();
        if(d > dist[u][p]) continue;
        if(u == n && p == 0) return d;

        for(pair<int, int> e : g[u]){
            int v = e.ff;
            long long w = e.ss;
            if(dist[v][1^p] > dist[u][p]+w){
                dist[v][1^p] = dist[u][p]+w;
                pq.push(mp(mp(-dist[v][1^p], v), 1^p));
            }
        }
    }

    return -1;
}


int main(){

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        assert(a <= n);
        assert(b <= n);
        assert(a >  0);
        assert(b >  0);
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    printf("%lld\n", dijkstra());


    return 0;
}
