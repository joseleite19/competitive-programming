#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<vector<bool>> visited;

int dfs(vector<bool> &v, int u){
	v[u] = true;
	for(int vertex : g[u])
		if(!v[vertex])
			dfs(v, vertex);
}

int main(){
	int n, spam;
	char words[100][3][21];
	int p[100];
	int t[2][100];

	while(scanf("%d", &n) == 1){
		g.assign(n, vector<int>());
		for(int i = 0; i < n; i++){
			int edge;
			while(scanf("%d", &edge) == 1 && edge)
				g[i].push_back(edge-1);

		}
		spam = 0;
		while(scanf("%d", p + spam) == 1 && p[spam]){
			p[spam]--;
			scanf("%d %d %s %s %s", &t[0][spam], &t[1][spam], words[spam][0], words[spam][1], words[spam][2]);
			spam++;
		}
		visited.assign(n, vector<bool>(n, false));
		for(int i = 0; i < n; i++){
			dfs(visited[i], i);
		}
		for(int i = 0; i < n; i++){
			char name[50];
			scanf("%s", name);
			printf("%s: ", name);
			for(int j = 0; j < spam; j++){
				if(visited[ p[j] ][i]){
					if(g[i].size() < t[0][j]) printf("%s ", words[j][0]);
					else if(g[i].size() < t[1][j]) printf("%s ", words[j][1]);
					else printf("%s ", words[j][2]);

				}
				else{
					printf("%s ", words[j][0]);
				}
			}
			printf("\n");
		}
	}

	return 0;
}