#include <bits/stdc++.h>

using namespace std;

const int N = 50004;

long long ans = 0;

vector<int> g[N];

int n, k;

vector<int> dfs(int u, int p){

    vector<int> ret(k+1, 0);
    ret[0]++;
    for(int v : g[u]) if(v != p){
       vector<int> tmp = dfs(v, u);
       for(int i = 0; i <= k; i++){
           ans += 1LL*ret[i] * tmp[k-i];
       }
       for(int i = 0; i <= k; i++) ret[i] += tmp[i];
    }
    for(int i = k; i > 0; i--)
        ret[i] = ret[i-1];
    ret[0] = 0;
    return ret;

}

int main(){

    scanf("%d %d", &n, &k);

    for(int i = 1; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, -1);

    printf("%lld\n", ans);

}
