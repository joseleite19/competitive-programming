#include <bits/stdc++.h>

using namespace std;

int w, s, x, y, mat[10004][105], mat2[10004][105], tot[105];

int main(){

	scanf("%d %d %d %d", &w, &s, &x, &y);

	for(int i = 0; i < w; i++)
		for(int j = 0; j < x; j++)
			scanf("%d", &mat[i][j]);

	for(int i = 0; i < s; i++)
		for(int j = 0; j < x; j++){
			scanf("%d", &mat2[i][j]);
			tot[j] = max(tot[j], mat2[i][j]);
		}

	for(int j = 0; j < x; j++)
		for(int k = 0; k < w; k++)
			mat[k][j] = min(mat[k][j], y - tot[j]);

	for(int i = 0; i < w; i++){
		printf("%d", mat[i][0]);
		for(int j = 1; j < x; j++)
			printf(" %d", mat[i][j]);
		printf("\n");
	}

	return 0;
}