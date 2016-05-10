#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

struct matrix{
	vector<vector<int> > v;
	int n;
	matrix(int size, bool identity = false){
		n = size;
		v.assign(n, vector<int>(n, 0));
		if(identity){
			for(int i = 0; i < n; i++)
				v[i][i] = 1;
		}
	}
	long long sum(){
		long long ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				ans = (ans + v[i][j]) % mod;
		return ans;
	}
	matrix operator*(const matrix & m)const{
		matrix ans = matrix(n);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				for(int k = 0; k < n; k++)
						ans.v[i][j] = (ans.v[i][j] + ((long long)(v[i][k] % mod)*(m.v[k][j] % mod)) % mod) % mod;
		return ans;
	}
};

int solve(matrix & m, long long k){
	matrix ans(m.n, 1);
	while(k){
		if(k & 1) ans = ans * m;
		m = m * m;
		k >>= 1;
	}
	return ans.sum();
}

int comp(int x1, int y1, int x2, int y2){
	if(x1 < x2){
		x1 = x1^x2;
		x2 = x1^x2;
		x1 = x1^x2;
	}
	if(y1 < y2){
		y1 = y1^y2;
		y2 = y1^y2;
		y1 = y1^y2;
	}

	if(x1 - x2 == 1 || y1 - y2 == 1) return 1;
	if(x1 - x2 == y1 - y2) return 0;
	if(x1 == x2 || y1 == y2) return 0;
	if((x1+x2) % 2 || (y1+y2) % 2) return 1;
	return 0;
}
int main(){
	int n;
	long long k;

	while(scanf("%d %lld", &n, &k) == 2){
		matrix buttons(n*n);

		for(int i = 0; i < n*n; i++)
			for(int j = 0; j < n*n; j++)
				buttons.v[i][j] = comp(i/n, i%n, j/n, j%n);

		printf("%d\n", solve(buttons, k));
	}

	return 0;
}