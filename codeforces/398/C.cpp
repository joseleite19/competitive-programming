#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

vector<int> g[1000006];
int tot, root, n, t[1000006], s[1000006];

vector<int> ans;

void dfs(int u){
	s[u] = t[u];

	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		dfs(v);
		s[u] += s[v];
	}

	if(u != root && s[u] == tot/3){
		ans.push_back(u);
		s[u] = 0;
	}
}

int main(){
	
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		int x;
		scanf("%d %d", &x, t+i); x--;
		tot += t[i];

		if(x == -1) root = i;
		else{
			g[x].push_back(i);
			// g[i].push_back(x);
		}
	}

	if(tot % 3){
		printf("-1\n");
		return 0;
	}

	dfs(root);

	if(ans.size() < 2) printf("-1\n");
	else printf("%d %d\n", ans[0]+1, ans[1]+1);

	return 0;
}