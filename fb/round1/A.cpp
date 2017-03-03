#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000000000000

using namespace std;

long long dp[303][303];
long long mark[303][303];
int pass;

long long c[303][303];

int n, m;

long long f(int i, int sum){
	long long &ret = dp[i][sum];

	if(i == n){
		return ret = (sum == n ? 0 : oo);
	}

	if(mark[i][sum] == pass) return ret;
	mark[i][sum] = pass;	
	
	ret = oo;

	if(sum >= i+1){
		ret = min(ret, f(i+1, sum));
	}

	for(int j = 1; j <= m && sum + j <= n; j++){ // comprar j tortas
		ret = min(ret, f(i+1, sum+j) + c[i][j-1]);
	}
	return ret;
}

int main(){
	int t;

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		scanf("%d %d", &n, &m);

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%lld", &c[i][j]);

		for(int i = 0; i < n; i++)
			sort(c[i], c[i]+m);

		for(int i = 0; i < n; i++)
			for(int j = 1; j < m; j++)
				c[i][j] += c[i][j-1];

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				c[i][j] += (j+1)*(j+1);

		pass++;
		printf("Case #%d: %lld\n", tc, f(0, 0));
	}

	return 0;
}