#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, r, c, matriz[105][105];

	while(scanf("%d %d %d %d", &n, &m, &r, &c) == 4 && n+m+r+c){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%1d", &matriz[i][j]);
		int plays = 0;
		for(int i = 0; i < n - r + 1; i++){
			for(int j = 0; j < m - c + 1; j++){
				if(matriz[i][j]){
					plays++;
					for(int k = 0; k < r; k++){
						for(int l = 0; l < c; l++){
							matriz[i+k][j+l] ^= 1;
						}
					}
				}
			}
		}
		// for(int i = 0; i < n; i++){
		// 	for(int j = 0; j < m; j++)
		// 		printf("%d ", matriz[i][j]);
		// 	printf("\n");
		// }
		bool possible = true;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(matriz[i][j])
					possible = false;

		printf("%d\n", possible ? plays : -1);
	}

	return 0;
}