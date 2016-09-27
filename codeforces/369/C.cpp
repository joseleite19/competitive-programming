#include <bits/stdc++.h>

#define oo 1000000000000000000

using namespace std;

int n, m, k;
int c[105];

int p[105][105];

long long dp[105][105][105];


long long f(int i, int j, int last){
	if(j > k) return oo;
	if(i == n && j == k) return 0;
	if(i == n) return oo;

	if(dp[i][j][last] != -1) return dp[i][j][last];

	if(c[i]){
		if(c[i] != last) return dp[i][j][last] = f(i+1, j+1, c[i]);
		return dp[i][j][last] = f(i+1, j, c[i]);
	}

	long long ans = oo;
	for(int ii = 1; ii <= m; ii++){
		if(ii != last) ans = min(ans, p[i][ii] + f(i+1, j+1, ii));
		else ans = min(ans, p[i][ii] + f(i+1, j, ii));
	}

	return dp[i][j][last] = ans;
}

int main(){

	scanf("%d %d %d", &n, &m, &k);

	for(int i = 0; i < n; i++)
		scanf("%d", c+i);

	for(int i = 0; i < n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &p[i][j]);

	memset(dp, -1, sizeof dp);
	long long ret = f(0, 0, 0);

	printf("%lld\n", ret == oo ? -1 : ret);

	return 0;
}