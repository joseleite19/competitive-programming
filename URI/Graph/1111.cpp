#include <bits/stdc++.h>

using namespace std;

#define INF 1000000007

int main(){
	int fw[11][11][11][11], n, a, b, c, d;

	while(scanf("%d", &n) == 1 && n){
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++) for(int l = 0; l < n; l++)
					fw[i][j][k][l] = (i == k && j == l ? 0 : INF);

		for(int i = n-1; i >= 0; i--){
			for(int j = 0; j < n; j++){
				scanf("%d %d %d %d", &a, &b, &c, &d);
				if(a) fw[i][j][i+1][j] = 1;
				if(b) fw[i][j][i-1][j] = 1;
				if(c) fw[i][j][i][j-1] = 1;
				if(d) fw[i][j][i][j+1] = 1;
			}
		}

		for(int q = 0; q < n; q++) for(int w = 0; w < n; w++)
			for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
				for(int k = 0; k < n; k++) for(int l = 0; l < n; l++)
					fw[i][j][k][l] = min(fw[i][j][k][l], fw[i][j][q][w] + fw[q][w][k][l]);

		int p;
		scanf("%d", &p);
		while(p--){
			scanf("%d %d %d %d", &a, &b, &c, &d);
			if(fw[b][a][d][c] == INF) printf("Impossible\n");
			else printf("%d\n", fw[b][a][d][c]);
		}
		printf("\n");
	}

	return 0;
}