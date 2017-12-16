#include <bits/stdc++.h>

char mat[100][100];

int n, m, t;

int main(){

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		scanf("%d %d", &n, &m);

		for(int i = 0; i < n; i++)
			scanf(" %s", mat[i]);

		for(int i = 0; i < n; i++){
			int j;
			for(j = 0; j < m; j++)
				if(mat[i][j] != '?')
					break;

			if(j == m){
				if(i == 0) continue;
				for(int j = 0; j < m; j++)
					mat[i][j] = mat[i-1][j];
			}
			else{
				for(int j = 0; j < m; j++){
					if(mat[i][j] == '?'){
						int k;
						for(k = j; k < m; k++)
							if(mat[i][k] != '?')
								break;
						if(k == m){
							for(k = j; k >= 0; k--)
								if(mat[i][k] != '?')
									break;
						}

						mat[i][j] = mat[i][k];
					}
				}
			}
		}
		
		for(int i = n-1; i >= 0; i--){
			int j;
			for(j = 0; j < m; j++)
				if(mat[i][j] != '?')
					break;

			if(j == m){
				for(int j = 0; j < m; j++)
					mat[i][j] = mat[i+1][j];
			}
			else{
				for(int j = 0; j < m; j++){
					if(mat[i][j] == '?'){
						int k;
						for(k = j; k < m; k++)
							if(mat[i][k] != '?')
								break;
						if(k == m){
							for(k = j; k >= 0; k--)
								if(mat[i][k] != '?')
									break;
						}

						mat[i][j] = mat[i][k];
					}
				}
			}
		}
		
		printf("Case #%d:\n", tc);
		for(int i = 0; i < n; i++)
			printf("%s\n", mat[i]);
	}




	return 0;
}