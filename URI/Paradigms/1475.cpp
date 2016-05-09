#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int t1, t2, n, f[1005], c;
int dp[1005];
int solve(int i){
	if(i >= n) return 0;
	if(dp[i] != -1) return dp[i];
	int aux = upper_bound(f, f + n, f[i] + t1) - f;
	int aux2 = upper_bound(f, f + n, f[i] + t2) - f;
	return dp[i] = min(t1 + solve(aux), t2 + solve(aux2));
}

int main(){

	while(scanf("%d %d %d %d", &n, &c, &t1, &t2) == 4){

		for(int i = 0; i < n; i++)
			scanf("%d", f + i);

		memset(dp, -1, sizeof dp);

		printf("%d\n", solve(0));
	}

	return 0;
}