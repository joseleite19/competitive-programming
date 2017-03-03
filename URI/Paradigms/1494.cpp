#include <bits/stdc++.h>

using namespace std;

char s[200];
int v[200], num[10];
long long dp[15][105][11];
int mark[15][105][11];
int n, pass;

#define MOD (1000000007)

long long dp2[200][200];

long long C(int j, int k){
	if(dp2[j][k] != -1) return dp2[j][k];
	if(j == k || j == 0 || k == 0) return 1;
	return dp2[j][k] = (C(j-1, k) + C(j-1, k-1)) % MOD;
}

int qnt[10];

long long f(int i, int plus, int minus, int sum){
	long long & ret = dp[i][plus][sum];

	if(mark[i][plus][sum] == pass) return ret;
	mark[i][plus][sum] = pass;
	
	ret = 0;
	if(i == 10) return ret = (sum == 0) ? 1 : 0;

	for(int j = 0; j <= qnt[i]; j++){
		if(j > plus || qnt[i] - j > minus) continue;
		int tmp = sum + (j%11)*i - (qnt[i] - j)*i;
		tmp = ((tmp % 11)+11)%11;

		long long tmp2 = (C(plus, j)*C(minus, qnt[i] - j))%MOD;

		ret = (ret + ((tmp2*f(i+1, plus-j, minus-(qnt[i] - j), tmp))%MOD))%MOD;
	}

	return ret;
}

int main(){

	memset(dp2, -1, sizeof dp2);

	while(scanf(" %s", s) == 1){
		pass++;

		memset(qnt, 0, sizeof qnt);

		n = strlen(s);
		for(int i = 0; i < n; i++) qnt[ s[i]-'0' ]++;

		int plus, minus;
		minus = n/2;
		plus = n - minus;

		int limit = min(plus-1, qnt[0]);
		long long ans = 0;
		for(int j = 0; j <= limit; j++){
			long long tmp = (C(plus-1, j)*C(minus, qnt[0] - j))%MOD;
			ans = (ans + (tmp*f(1, plus-j, minus - (qnt[0] - j), 0))%MOD)%MOD;
		}

		printf("%lld\n", ans);
	}

	return 0;
}