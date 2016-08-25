#include <bits/stdc++.h>

using namespace std;

int matriz[1005][26];

void dfs(int v, vector<char> vetor){
	for(int u = 0; u < 26; u++){
		if(matriz[v][u] != -1){
			printf("%c\n", u+'a');
			printf("%c", u+'a');
			dfs(matriz[v][u], {});
			printf("\n");
		}
	}
}

int main(){
	char s[1005];

	while(scanf(" %s", s) == 1){
		memset(matriz, -1, sizeof matriz);

		int size = strlen(s);
		for(int i = 0; i < size; i++){
			if(matriz[0][ s[i]-'a' ] == -1){
				matriz[0][ s[i]-'a' ] = i+1;
			}
			for(int j = i; j < size; j++){
				if(matriz[i][ s[j]-'a' ] == -1){
					matriz[i][ s[j]-'a' ] = j+1;
				}
			}
		}
		for(int i = 0; i < size+1; i++){
			for(int j = 0; j < 26; j++){
				// if(matriz[i][j] != -1)
					// printf("%c ", s[ matriz[i][j]-1 ]);
				// else huehue
					printf("%d ", matriz[i][j]);
			}

			printf("\n");
		}
		dfs(0, {});
	}

	return 0;
}