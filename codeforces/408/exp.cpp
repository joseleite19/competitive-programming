#include <bits/stdc++.h>

#define MOD (1000000007)

using namespace std;

void mult(long long a[4][4], long long b[4][4]){
	long long c[4][4];
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			c[i][j] = 0;
			for(int k = 0; k < 4; k++)
				c[i][j] = (c[i][j] + a[i][k]*b[j][k]) % MOD;
		}
	}
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
				a[i][j] = c[i][j];
}

long long f(int n){
	long long a[4][4];
	long long ans[4][4];
	for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) a[i][j] = 1, ans[i][j] = 0;
	for(int i = 0; i < 4; i++) a[i][i] = 0, ans[i][i] = 1;

	while(n){
		if(n & 1) mult(ans, a);
		mult(a, a);
		n >>= 1;
	}
	return ans[3][3];
}

int main(){

	for(int i = 1; i < 100; i++)
		printf("%d %lld\n", i, f(i));


	return 0;
}