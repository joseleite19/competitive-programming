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

int mat[200][200];

int main(){

	int n, m;

	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			char c;
			scanf(" %c", &c);
			mat[i][j] = c - '0';
		}



	int ans = 0;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			// printf("%d ", mat[i][j]);
			if(!mat[i][j]) continue;
			int old = ans;
			ans += 2;
			if(mat[i][j] > mat[i+1][j]) ans += mat[i][j] - mat[i+1][j];
			if(mat[i][j] > mat[i-1][j]) ans += mat[i][j] - mat[i-1][j];
			if(mat[i][j] > mat[i][j+1]) ans += mat[i][j] - mat[i][j+1];
			if(mat[i][j] > mat[i][j-1]) ans += mat[i][j] - mat[i][j-1];
			// printf("%d %d - %d\n", i, j, ans - old);
		}
		// printf("\n");
	}

	printf("%d\n", ans);





	return 0;
}