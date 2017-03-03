#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	char mat[505][505];

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		scanf(" %s", mat[i]);

	bool rec = true;
	int L = -1, R = -1;
	bool found = false;
	int i;

	int limit = 0;

	for(i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j] == 'X'){
				limit = i;
			}
		}
	}

	for(i = 0; i < n && !found; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j] == 'X'){
				found = true;
				if(L == -1) L = j;
				R = j;
			}
		}
	}

	for(; i <= limit; i++){
		for(int j = 0; j < m; j++){
			if(L <= j && j <= R){
				if(mat[i][j] == '.') rec = false;
			}
			else if(mat[i][j] == 'X'){
				rec = false;
			}
		}
	}

	printf("%s\n", rec ? "YES" : "NO");


	return 0;
}