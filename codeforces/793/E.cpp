#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;


vector<int> g[5003];

int cnt[5003], a, b, c, d, vis[5003], p[5003];

int dfs(int u){

	for(int v : g[u]){
		cnt[u] += dfs(v);
		vis[u] |= vis[v];
	}

	if(g[u].empty()){
		cnt[u]++;
		if(u == a) vis[u] = 1;
		if(u == b) vis[u] = 2;
		if(u == c) vis[u] = 4;
		if(u == d) vis[u] = 8;
	}
	return cnt[u];
}

vector<int> v;

bool dp[5003][5003];
int mark[5003][5003], pass;

bool f(int i, int j){
	if(j < 0) return 0;
	if(j == 0) return 1;
	if(i == v.size()) return 0;

	bool &ans = dp[i][j];

	if(mark[i][j]) return ans;
	mark[i][j] = 1;

	return ans = f(i+1, j) | f(i+1, j - v[i]);
}

int main(){
	int n;

	scanf("%d", &n);

	scanf("%d %d %d %d", &a, &b, &c, &d);

	for(int i = 2; i <= n; i++){
		scanf("%d", p+i);
		g[p[i]].push_back(i);
	}

	dfs(1);

	if(cnt[1] % 2) return printf("NO\n"), 0;

	int sza, szb, szc, szd;
	for(int u : g[1]){
		if(!vis[u])
			v.push_back(cnt[u]);
		else{
			if(vis[u] == 1) sza = cnt[u];
			if(vis[u] == 2) szb = cnt[u];
			if(vis[u] == 4) szc = cnt[u];
			if(vis[u] == 8) szd = cnt[u];
		}
	}

	// printf("%d %d %d %d\n", sza, szb, szc, szd);

	// printf("%d %d\n", (cnt[1] - 2)/2 - szc, (cnt[1] - 2)/2 - szb);
	// printf("%d %d\n", f(0, (cnt[1] - 2)/2 - szc), f(0, (cnt[1] - 2)/2 - szb));

	int can1 = 0, can2 = 0;

	{
		for(int i = 0; i < sza; i++){
			for(int j = 0; j < szb; j++)
				can1 |= f(0, (cnt[1] - 2)/2 - szc - i - j);
		}
	}
	{
		for(int i = 0; i < szc; i++){
			for(int j = 0; j < szd; j++)
				can2 |= f(0, (cnt[1] - 2)/2 - szb - i - j);
		}
	}


	if(can1 && can2)
		printf("YES\n");
	else printf("NO\n");




	return 0;
}