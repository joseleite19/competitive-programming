#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

vector<int> g[100005];

int cnt[100005];

int dfs(int u, int p, int h){
	cnt[u] = h;

	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(v == p) continue;
		dfs(v, u, -h);
	}
}

int main(){
	file();
	int n, k;

	scanf("%d %d", &n, &k);

	for(int i = 1; i <= n; i++){
		int qnt = 0;
		scanf("%d", &qnt);
		int x;
		while(qnt--){
			scanf("%d", &x);
			g[i].push_back(x);
		}
	}

	dfs(k, k, 1);

	for(int i = 1; i <= n; i++){
		if(g[i].size() <= 1){
			printf("%s\n", cnt[i] == 1 ? "CW" : (cnt[i] == -1 ? "CCW" : "-"));
		}
	}




	return 0;
}