#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

long long resp[4];
void mult(long long a[], long long b[]){

	resp[0] = (a[0]*b[0] + a[1]*b[2]) % MOD;
	resp[1] = (a[0]*b[1] + a[1]*b[3]) % MOD;
	resp[2] = (a[2]*b[0] + a[3]*b[2]) % MOD;
	resp[3] = (a[2]*b[1] + a[3]*b[3]) % MOD;

	for(int i = 0; i < 4; i++) a[i] = resp[i];
}

int main(){

	int x;
	
	scanf("%d", &x);

	long long base[4] = {1, 1, 1, 0};

	for(int i = 0; i < x; i++){
		// long long mat[4] = {1, 0, 0, 1};
		// long long e = 100;
		long long e = 100000;

		// while(e--)
			// mult(base, base);
		while(e){
			if(e & 1) mult(mat, base);
			mult(base, base);
			e >>= 1;
		}
		for(int i = 0; i < 4; i++) base[i] = mat[i];
	}

	printf("%lld\n", base[2]);



	return 0;
}