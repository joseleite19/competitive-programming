#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 333;

vector<vector<int> > g;
int s[N], t[N], vis[N];
int d, p, r, b;

pair<int, int> dfs(int u, int b){ // diff, cost
    vis[u] = 1;

    pair<int, int> ans;
    ans.ff = 1;
    if(u < d) ans.ss = s[u];
    else ans.ss = t[u-d];

    for(int v : g[u]) if(!vis[v]){
        pair<int, int> tmp = dfs(v, 1^b);
        ans.ff -= tmp.ff;
        ans.ss += tmp.ss;
    }
    return ans;
}

int dif[N], cost[N], n;

int dp[N][2][33333];
int mark[N][2][33333], pass;
int f(int i, int q, int m){
    if(i == n) return 0;

    int &ans = dp[i][q][m];
    if(mark[i][q][m] == pass) return ans;
    mark[i][q][m] = pass;
    ans = f(i+1, q, m);
    
    if(m >= cost[i]){
        if(!q) ans = max(ans, f(i+1, q, m - cost[i]) - dif[i]);
        else ans = max(ans, f(i+1, q, m - cost[i]) + dif[i]);
    }

    return ans;
}

int main(){

	while(scanf("%d %d %d %d", &d, &p, &r, &b) == 4){
        g.assign(d+p, vector<int>());
        
        for(int i = 0; i < d; i++)
            scanf("%d", s+i);

        for(int i = 0; i < p; i++)
            scanf("%d", t+i);

        for(int i = 0; i < r; i++){
            int a, b;
            scanf("%d %d", &a, &b); a--, b--;

            g[a].emplace_back(b+d);
            g[b+d].emplace_back(a);
        }
        n = 0;
        for(int i = 0; i < d; i++) if(!vis[i]){
            pair<int, int> tmp = dfs(i, 0);
            dif[n] = tmp.ff;
            cost[n] = tmp.ss;
            n++;
        }
        for(int i = 0; i < p; i++) if(!vis[i+d]){
            pair<int, int> tmp = dfs(i+d, 0);
            dif[n] = -tmp.ff;
            cost[n] = tmp.ss;
            n++;
        }
        pass++;
        printf("%d %d\n", d + f(0, 0, b), p + f(0, 1, b));
	}


	return 0;
}
