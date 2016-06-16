#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

int n;
int id(int x, int y){
	return n*x + y;
}


int fw[11][11][11][11];

int main(){
	int a, b, c, d;

	while(scanf("%d", &n) && n){
		// fw.assign(n, vector<vector< vector<int > > >(n, vector< vector<int > >(n, vector<int>(n, INF))));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					for(int ii = 0; ii < n; ii++){
						fw[i][j][k][ii] = INF;
					}
				}
			}
		}

		for(int i = n-1; i >= 0; i--){
			for(int j = 0; j < n; j++){
				scanf("%d %d %d %d", &a, &b, &c, &d);
				if(a) fw[i][j][i+1][j] = 1;
				if(b) fw[i][j][i-1][j] = 1;
				if(c) fw[i][j][i][j-1] = 1;
				if(d) fw[i][j][i][j+1] = 1;
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					for(int l = 0; l < n; l++){
						for(int q = 0; q < n; q++){
							for(int w = 0; w < n; w++){
								fw[i][j][k][l] = min(fw[i][j][k][l], fw[i][j][q][w] + fw[q][w][k][l]);					
							}
						}
					}
				}
			}
		}
		int q;
		scanf("%d", &q);
		while(q--){
			scanf("%d %d %d %d", &a, &b, &c, &d);
			// a = n-1-a;
			// b = n-1-b;
			// c = n-1-c;
			// d = n-1-d;
			// printf("%d %d %d %d\n", a, b, c, d);
			if(fw[a][b][c][d] == INF) printf("Impossible\n");
			else printf("%d\n", fw[a][b][c][d]);
		}
		printf("asdas\n");fflush(stdout);
	}

	return 0;
}