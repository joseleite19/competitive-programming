#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;
vector<int> g[200005];

vector<int> bfs(int s){
    vector<int> dist(n, 100000000);

    dist[s] = 0;

    queue<int> q; q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(int v : g[u])
            if(dist[v] == 100000000)
                dist[v] = dist[u]+1, q.push(v);
    }

    return dist;
}

int main(){

    int x;

    scanf("%d %d", &n, &x); x--;

    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d %d", &u, &v); u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> d1 = bfs(0);

    vector<int> d2(n, -1);

    queue<int> q;
    q.push(x);

    d2[x] = 0;

    int ans = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        ans = max(ans, 2*d1[u]);
        for(int v : g[u]) if(d2[v] == -1){
            d2[v] = d2[u]+1;
            if(d2[v] < d1[v]){
                q.push(v);
            }
            else if(d2[v] == d1[v]){
                ans = max(ans, 2*d1[v]);
            }
        }
    }

    printf("%d\n", ans);


    return 0;
}
