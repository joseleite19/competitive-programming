#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 505;

int mat[N][N];
int n, m;

int main(){

	int t;

	scanf("%d", &t);

	while(t--){
		scanf("%d %d", &n, &m);
		int x = 1;
		for(int s = n-1 + m-1; s >= 0; s--){
			for(int i = 0; i <= s; i++){
				int j = s - i;
				if(i < 0 || i >= n || j < 0 || j >= m)
					continue;
				mat[i][j] = x++;
			}
		}
		for(int i = 0; i < n; i++){
			printf("%d", mat[i][0]);
			for(int j = 1; j < m; j++)
				printf(" %d", mat[i][j]);
			printf("\n");
		}
	}




    return 0;
}
