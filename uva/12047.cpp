#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back
#define oo (1000000000000000000)

using namespace std;

vector<long long> dijkstra(const vector<vector<pair<int, int> > >& g, int s){

    vector<long long> dist(g.size(), oo);

    priority_queue<pair<long long, int> > pq;
    dist[s] = 0;
    pq.push(mp(0LL, s));

    while(!pq.empty()){
        int u = pq.top().ss;
        long long d = -pq.top().ff; pq.pop();
        if(dist[u] < d) continue;

        for(auto x : g[u]){
            int v = x.ff, w = x.ss;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push(mp(-dist[v], v));
            }
        }
    }

    return dist;
}

int main(){

    int t;

    scanf("%d", &t);

    while(t--){
        int n, m, s, t, p;
        
        scanf("%d %d %d %d %d", &n, &m, &s, &t, &p); s--; t--;
        vector<vector<pair<int, int> > > g(n, vector<pair<int, int> >());
        vector<vector<pair<int, int> > > h(n, vector<pair<int, int> >());

        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w); u--; v--;
            g[u].eb(v, w);
            h[v].eb(u, w);
        }

        vector<long long> d1 = dijkstra(g, s);
        vector<long long> d2 = dijkstra(h, t);
        
        int ans = -1;
        for(int u = 0; u < n; u++){
            for(auto x : g[u]){
                int v = x.ff, w = x.ss;
                if(d1[u] + w + d2[v] <= p)
                    ans = max(ans, w);
            }
        }

        printf("%d\n", ans);    
    }



    return 0;
}
