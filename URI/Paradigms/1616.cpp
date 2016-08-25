#include <bits/stdc++.h>

using namespace std;

#define MOD (1000000007)

int dp[1005][1005];

int b, g;
int f(int i, int j){
	if(dp[i][j] != -1) return dp[i][j];
	if(j == 0 && i == 0) return 1;
	if(j == 0) return 0;
	if(i == 0) return dp[i][j] = ((long long)f(i, j-1) * g) % MOD;
	return dp[i][j] = ((long long)f(i, j-1) * (g-i) + (long long)f(i-1, j-1) * i) % MOD;
}
int main(){

	while(scanf("%d %d", &b, &g) == 2 && b + g){
		memset(dp, -1, sizeof dp);

		printf("%d\n", f(g, b));
	}
}