#include <bits/stdc++.h>

using namespace std;

int magic = 200000;

vector<int> g[400005];

vector<int> dfs_num, dfs_low, S, visited;
int cnt = 1;
int can = 1;

int ssc[400005];
int ssc_cnt = 1;

void tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = cnt++; // dfs_low[u] <= dfs_num[u]
	S.push_back(u);	// stores u in a vector based on order of visitation
	visited[u] = 1;
	for(int j = 0; j < (int)g[u].size(); j++) {
		int v = g[u][j];
		if(dfs_num[v] == 0)
			tarjanSCC(v);
		if(visited[v]) // condition for update
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if (dfs_low[u] == dfs_num[u]) { // if this is a root (start) of an SCC
		int q = 0;
		vector<int> qq;
		ssc_cnt++;
		while (1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			// q++;
			ssc[v] = ssc_cnt;
			// qq.push_back(v);
			if(u == v) break;
		}
		// if(q > 1){
		// 	printf("%d\n", q);
		// 	while(!qq.empty()) printf("..%d\n", qq.back()), qq.pop_back();
		// }
		// if(q > 1) can = false;
	}
}


int n, m, r[100005];
vector<int> w[100005];
int main(){


	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		scanf("%d", r+i);

	for(int i = 0; i < m; i++){
		int x, tmp;
		scanf("%d", &x);

		for(int j = 0; j < x; j++){
			scanf("%d", &tmp);
			tmp--;
			w[tmp].push_back(i);
		}
	}

	for(int i = 0; i < n; i++){
		int a = w[i][0], b = w[i][1];
		if(r[i]){ //unlocked
			g[magic+a].push_back(b);
			g[magic+b].push_back(a);

			g[a].push_back(b);
			g[magic+b].push_back(a);

			g[magic+a].push_back(b);
			g[b].push_back(a);
		}
		else{ // locked
			g[magic+a].push_back(b);
			g[magic+b].push_back(a);

			g[a].push_back(magic+b);
			g[b].push_back(magic+a);
		}
	}

	dfs_num.assign(2*magic, 0); dfs_low.assign(2*magic, 0); visited.assign(2*magic, 0);
	
	for(int i = 0; i < 2*magic; i++)
		if(dfs_num[i] == 0)
			tarjanSCC(i);

	for(int i = 0; i < m; i++)
		if(ssc[i] == ssc[i+magic])
			can = false;

	printf("%s\n", can ? "YES" : "NO");

	return 0;
}