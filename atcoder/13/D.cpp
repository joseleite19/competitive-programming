#include <bits/stdc++.h>

#define MOD (1000000007)

using namespace std;

long long pot(long long base, long long exp){
	long long ans = 1;
	while(exp){
		if(exp & 1) ans = (ans * base) % MOD;
		base = (base * base) % MOD;
		exp >>= 1;
	}
	return ans;
}

long long dp[6002][3003];

long long C(int n, int k){
	if(n == 0 || k == 0 || n == k) return 1;
	if(dp[n][k] != -1) return dp[n][k];
	return dp[n][k] = (C(n-1, k-1) + C(n-1, k)) % MOD;
}

int main(){
	int n, m;
	memset(dp, -1, sizeof dp);

	scanf("%d %d", &n, &m);

	long long ans = 0;
	if(2*m <= n){ // nothing to do
		ans = pot(2, 2*m);
	}
	else if(2*m > n){ //need to take out something
		ans = pot(2, n);
		long long tmp = 0;
		int left = 2*m - n; 
		for(int i = 0; i <= m; i++){
			if(left - i > m){
			// printf("%d %d %lld %lld\n", left, i, tmp, ans);
				continue;
			}
			tmp = (tmp + C(left, i)) % MOD;
		}
		// printf("%lld %lld\n", ans, tmp);
		ans = (ans * tmp) % MOD;
	}

	printf("%lld\n", ans);


	return 0;
}