#include <bits/stdc++.h>

#define MOD (998244353)

using namespace std;

void file(){
	freopen("figure.in", "r", stdin);
	freopen("figure.out", "w", stdout);
}

void mult(long long a[4][4], long long b[4][4]){
	long long c[4][4];
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			c[i][j] = 0;
			for(int k = 0; k < 4; k++)
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
		}
	}

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			a[i][j] = c[i][j];
}

long long f(long long b[4][4], long long e){
	long long ans[4][4];
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			ans[i][j] = i == j;
	while(e){
		if(e & 1) mult(ans, b);
		mult(b, b);
		e >>= 1;
	}
	return ans[0][0];
}


int main(){
	file();

	int n;

	while(scanf("%d", &n) == 1 && n){
		long long mat[4][4] = {{1, 1, 1, 0},
							   {1, 2, 2, 0},
							   {0, 0, 1, 1},
							   {0, 1, 2, 1}};
		printf("%lld\n", f(mat, n));
	}

}