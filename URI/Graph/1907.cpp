#include <bits/stdc++.h>

using namespace std;

int n, m;
char matriz[1025][1025];

bool passed[1025][1025];

void dfs(int i, int j){
	passed[i][j] = true;
	if(i > 0 && matriz[i-1][j] == '.' && !passed[i-1][j]) dfs(i-1,j);
	if(i < n-1 && matriz[i+1][j] == '.' && !passed[i+1][j]) dfs(i+1,j);
	if(j > 0 && matriz[i][j-1] == '.' && !passed[i][j-1]) dfs(i,j-1);
	if(j < m-1 && matriz[i][j+1] == '.' && !passed[i][j+1]) dfs(i,j+1);
}

int main(){

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf(" %c", &matriz[i][j]);

	int comp = 0;

	memset(passed, 0, sizeof passed);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matriz[i][j] == '.' && !passed[i][j]){
				comp++;
				dfs(i, j);
			}
		}
	}

	printf("%d\n", comp);

	return 0;
}