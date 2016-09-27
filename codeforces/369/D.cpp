#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

vector<int> g[200005];
int color[200005], n, L[200005];
vector<int> c;
int pot(int b, int exp){
	int ans = 1;
	while(exp){
		if(exp & 1) ans = ((long long)ans*b) % MOD;
		b = ((long long)b*b) % MOD;
		exp >>= 1;
	}
	return ans;
}

int ans = 1;

bool incre = true;

void dfs(int u, int length){
	if(color[u] == 2){
		ans = ((long long)ans * pot(2, length)) % MOD;
		// printf("dsad %d\n", ans);
		return;
	}
	if(color[u] == 1){
		ans = ((long long)ans * (pot(2, length - L[u]) - 2 + MOD)) % MOD;
		// printf("sad %d\n", ans);
		if(incre) c.push_back(u);
		color[u] = 2;
		return;
	}

	L[u] = length;
	color[u] = 1;

	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		dfs(g[u][i], length+1);
	}

	color[u] = 2;
}

int main(){

	scanf("%d", &n);

	int x;
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		g[i].push_back(x);
	}

	for(int i = 1; i <= n; i++)
		dfs(i, 0);

	memset(color, 0, sizeof color);

	ans = 1;
	incre = false;

	for(int i = 0; i < c.size(); i++)
		dfs(c[i], 0);

	for(int i = 1; i <= n; i++)
		dfs(i, 0);

	printf("%d\n", ans);

	return 0;
}