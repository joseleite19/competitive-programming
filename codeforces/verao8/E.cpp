#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

set<int> ans;

bool mark[202][202];

int n;
int mat[202][202], k, v[202];

void dfs(int u, int t){
	if(mark[u][t]) return;
	mark[u][t] = 1;
	if(t == k){
		ans.insert(u+1);
		return;
	}

	for(int i = 0; i < n; i++){
		if(mat[u][i] && mat[u][i] == v[t]){
			dfs(i, t+1);
		}
	}

}

int main(){
	file();

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);

	scanf("%d", &k);

	for(int i = 0; i < k; i++)
		scanf("%d", v+i);

	dfs(0, 0);

	printf("%d\n", (int)ans.size());

	for(set<int>::iterator it = ans.begin(); it != ans.end(); it++)
		printf("%d ", *it);
	printf("\n");





	return 0;
}