#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 3003;
const int oo = 1000000000;

vector<int> g[N];
int mat[N][N];
int n, m;

void dijkstra(int s){
    for(int i = 1; i <= n; i++)
        mat[s][i] = -1;
    mat[s][s] = 0;
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : g[u]) if(mat[s][v] == -1){
            mat[s][v] = mat[s][u]+1;
            q.push(v);
        }
    }
}

int f(int u, int w){
    if(w == 4) return 0;

    int ans = 0;
    for(int i = 1; i <= n; i++) if(mat[u][i] != -1 && i != u){
        ans = max(ans, f(i, w+1) + mat[u][i]);
    }
    return ans;
}

int main(){

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
    }

    for(int i = 1; i <= n; i++)
        dijkstra(i);

    printf("%d\n", f(0, 0));

    return 0;
}
