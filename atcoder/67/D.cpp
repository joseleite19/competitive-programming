#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD 1000000007
#define oo 1000000000000000000

using namespace std;

const int N = 100005;

int n;

vector<int> g[N];

vector<int> bfs(int s){
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v: g[u]){
            if(dist[v] == -1){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main(){

    scanf("%d", &n);

    for(int i = 1; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> d1 = bfs(1);
    vector<int> d2 = bfs(n);

    int l = 0, r = 0;
    for(int i = 1; i <= n; i++){
        if(d1[i] <= d2[i]) l++;
        else r++;
    }

    if(l > r) printf("Fennec\n");
    else if(r >= l) printf("Snuke\n");




    return 0;
}
