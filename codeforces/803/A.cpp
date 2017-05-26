#include <bits/stdc++.h>

using namespace std;

int n, k, mat[200][200];

int main(){

	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i++){
		if(k >= 1){
			k--;
			mat[i][i] = 1;
		}
		for(int j = i+1; j < n; j++){
			if(k >= 2){
				mat[i][j] = mat[j][i] = 1;
				k -= 2;
			}
		}
	}

	if(k) return printf("-1\n"), 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}



	return 0;
}