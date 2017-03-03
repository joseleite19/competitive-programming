#include <bits/stdc++.h>

using namespace std;

int n, m, W, b[1003], w[1003];

vector<int> g[1003];

int comp, vis[1003];

vector<int> componente[1003];

int totW[1003], totB[1003];

void dfs(int u, int cmp){
	vis[u] = 1;
	componente[cmp].push_back(u);
	totB[cmp] += b[u];
	totW[cmp] += w[u];
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(!vis[v]){
			dfs(v, cmp);
		}
	}
}

int dp[1003][1003];

long long f(int i, int peso){
	if(dp[i][peso] != -1) return dp[i][peso];
	if(i == comp) return 0;

	long long ret = f(i+1, peso);

	for(int j = 0; j < (int)componente[i].size(); j++){
		int v = componente[i][j];
		if(w[v] <= peso){
			ret = max(ret, f(i+1, peso - w[v]) + b[v]);
		}
	}

	if(totW[i] <= peso)
		ret = max(ret, f(i+1, peso - totW[i]) + totB[i]);

	return dp[i][peso] = ret;
}

// max(pegar 0, pegar 1, pegar tudo)

int main(){

	scanf("%d %d %d", &n, &m, &W);

	for(int i = 0; i < n; i++)
		scanf("%d", w+i);
	for(int i = 0; i < n; i++)
		scanf("%d", b+i);

	int x, y;

	for(int i = 0; i < m; i++){
		scanf("%d %d", &x, &y), x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	for(int i = 0; i < n; i++){
		if(!vis[i]){
			dfs(i, comp);
			comp++;
		}
	}

	memset(dp, -1, sizeof dp);

	printf("%lld\n", f(0, W));
}
