#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int mat[1003][1003];
int sumH[1003][1003];
int sumV[1003][1003];
int main(){
	int n, m;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &mat[i][j]);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			sumH[i][j] = mat[i][j] + (j ? sumH[i][j-1] : 0);
	
	for(int j = 0; j < m; j++)
		for(int i = 0; i < n; i++)
			sumV[i][j] = mat[i][j] + (i ? sumV[i-1][j] : 0);

	int ans = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j]) continue;
			if(sumH[i][j]) ans++;
			if(sumV[i][j]) ans++;
			if(sumH[i][m-1] - sumH[i][j]) ans++;
			if(sumV[n-1][j] - sumV[i][j]) ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}