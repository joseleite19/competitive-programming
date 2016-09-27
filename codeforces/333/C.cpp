#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000

using namespace std;

int x[105], n, m, k;

int mm;
int mark[105][100005];

long long dp[105][100005];
long long f(int i, int sum){
	// printf("%d %d %d\n", i, sum, k);

	if(mark[i][sum]) return dp[i][sum];
	mark[i][sum] = 1;

	if(i == n+1){
		printf("asd %d %d %d\n", i, sum, k);
		if(sum < k) return dp[i][sum] = 1;
		return dp[i][sum] = 0;
	}

	long long ans = 0;
	for(int j = 1; j <= m; j++){
		if(x[i] == j) continue;
		ans += f(i+1, sum+j);
		if(ans < 0) printf("%d %d %lld %d %lld %d %d\n", i, sum, ans, j, f(i+1, sum+j), i+1, sum+j);
	}

	// printf("%lf\n", ans);
	
	// printf("%lld\n", ans);
	return dp[i][sum] = ans;
}

int main(){

	memset(dp, -1, sizeof dp);

	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++){
		scanf("%d", x+i);
		k += x[i];
	}

	printf("%lld\n", f(0, 0));

	return 0;
}