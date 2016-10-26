#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int mat[30][30], n, m;

bool bt(int i){
	if(i == n) return true;

	int cnt = 0;
	for(int j = 0; j < m; j++)
		if(mat[i][j]-1 != j)
			cnt++;

	if(cnt <= 2) return bt(i+1);

	return false;
}

int main(){

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &mat[i][j]);

	bool can = false;
	for(int q = 0; q < m; q++){
		for(int w = q; w < m; w++){
			for(int j = 0; j < n; j++)
				swap(mat[j][q], mat[j][w]);

			can |= bt(0);
			
			for(int j = 0; j < n; j++)
				swap(mat[j][q], mat[j][w]);
		}
	}

	printf("%s\n", can ? "YES" : "NO");

	return 0;
}