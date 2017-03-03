#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int n, m;

vector<vector<int> > mat;
vector<vector<int> > mat2;

int maxr[100005];

int main(){

	scanf("%d %d", &n, &m);

	mat.assign(n, vector<int>(m, 0));
	mat2.assign(n, vector<int>(m, 0));

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &mat[i][j]);

	for(int j = 0; j < m; j++)
		mat2[0][j] = 1;

	for(int i = 1; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i-1][j] <= mat[i][j])
				mat2[i][j] = mat2[i-1][j]+1;
			else
				mat2[i][j] = 1;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			maxr[i] = max(maxr[i], mat2[i][j]);
	}

	int k, l, r;

	scanf("%d", &k);

	while(k--){
		scanf("%d %d", &l, &r);
		r--, l--;

		printf("%s\n", l >= r - maxr[r] + 1 ? "Yes" : "No");
	}


	return 0;
}