#include <bits/stdc++.h>

#define ff first
#define ss second
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define MOD 1000000007LL

using namespace std;
typedef long long ll;

const int N = 100005;

int n, m;

int sh[N];

ll v[N][30];
int L[N];

vector<int> g[N];

void dfs(int u){
    v[u][ L[u] ] = sh[u];

    for(int w : g[u]){
        L[w] = L[u]+1;
        dfs(w);
        for(int i = 0; i < 30; i++){
            v[u][i] += v[w][i];
        }
    }
}

ll f(int u){
    ll ans = 0;

    for(int i = 0; i < 30; i++)
        ans = max(ans, v[1][i] - v[u][i]);
    return ans;
}

int main(){

    scanf("%d %d %d", &n, &m, sh+1);

    for(int i = 1; i < n; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[v].push_back(u);
        sh[u] = w;
    }

    dfs(1);

    int x;
    for(int i = 0; i < m; i++){
        scanf("%d", &x);

        printf("%lld\n", f(x));
    }


    return 0;
}
