#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 200005;

int n, k;
vector<int> g[N];
int dist[N];

void make_tree(){
    queue<int> q;

    int mx = 1;
    for(int i = 0; i < k; i++){
        g[1].push_back(i+2);
        g[i+2].push_back(1);
        q.push(i+2);
        mx = i+2;
    }

    while(!q.empty() && mx < n){
        int u = q.front(); q.pop();
        g[u].push_back(mx+1);
        g[mx+1].push_back(u);
        q.push(mx+1);
        mx++;
    }
}

int diameter(){
    memset(dist, -1, sizeof dist);

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    int mx = -1, w = -1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(dist[u] > mx) mx = dist[u], w = u;
        for(int v : g[u]){
            if(dist[v] == -1){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }

    memset(dist, -1, sizeof dist);

    mx = -1;
    q.push(w);
    dist[w] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        if(dist[u] > mx) mx = dist[u];
        for(int v : g[u]){
            if(dist[v] == -1){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }

    return mx;
}

void dfs(int u, int p){
    
    for(int v : g[u]) if(v != p){
        printf("%d %d\n", u, v);
        dfs(v, u);
    }
}

int main(){

    scanf("%d %d", &n, &k);

    make_tree();

    printf("%d\n", diameter());

    dfs(1, -1);

    return 0;
}
