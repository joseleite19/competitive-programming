#include <bits/stdc++.h>

using namespace std;
int n, m, q, grid[205][205], toRight[205][205];


bool possible(int x){
	for(int i = 0; i < n - x + 1 && !possible; i++){
		for(int j = 0; j < m; j++){
			bool tmp = true;
			for(int k = 0; k < x; k++)
				if(toRight[i+k][j] < x)
					tmp = false;

			if(tmp) return true;
		}
	}
	return false;
}

int main(){

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &grid[i][j]);


	memset(toRight, 0, sizeof toRight);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			toRight[i][j] = 0;
			int k;
			for(k = j; k < m && grid[i][k]; k++);
			toRight[i][j] = k-j;
		}
	}

	scanf("%d", &q);

	while(q--){
		int x;
		scanf("%d", &x);

		if(possible(x)) printf("yes\n");
		else printf("no\n");
	}

	return 0;
}