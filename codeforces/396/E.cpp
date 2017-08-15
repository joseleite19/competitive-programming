#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

const int B = 22;

int d[N][22][2];

int c[N];

long long ans;

vector<int> g[N];

int dfs(int u, int p){

    for(int i = 0; i < B; i++){
        if(c[u] & (1 << i)) d[u][i][1]++;
        else d[u][i][0]++;
    }

    ans += c[u];

    for(int v : g[u]) if(v != p){
        dfs(v, u);
        for(int i = 0; i < B; i++){
            ans += 1LL * d[u][i][1] * d[v][i][0] * (1 << i);
            ans += 1LL * d[u][i][0] * d[v][i][1] * (1 << i);
            if(c[u] & (1 << i)){
                d[u][i][0] += d[v][i][1];
                d[u][i][1] += d[v][i][0];
            }
            else{
                d[u][i][0] += d[v][i][0];
                d[u][i][1] += d[v][i][1]; 
            }
        }
    }
}

int main(){

    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d", c+i);

    for(int i = 1; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 1);

    printf("%lld\n", ans);



	return 0;
}
