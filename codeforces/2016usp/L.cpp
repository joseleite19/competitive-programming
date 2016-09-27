#include <bits/stdc++.h>

using namespace std;


int w[1005], c[1005], n;
long long dp[10004];

long long f(int x){
	
	if(dp[x] != -1) return dp[x];

	long long ans = 0;
	for(int i = 0; i < n; i++)
		if(w[i] <= x)
			ans = max(ans, c[i]+f(x-w[i]));

	return dp[x] = ans;
}

int main(){

	int s;

	while(scanf("%d", &n) == 1 && n){
		memset(dp, -1, sizeof dp);
		scanf("%d", &s);

		for(int i = 0; i < n; i++)
			scanf("%d %d", w+i, c+i);

		long long ans = 0;

		for(int i = 0; i < n; i++){
			int tmp = max(s/w[i], 0);
			ans = max(ans, (long long)tmp*c[i] + f(s - tmp*w[i]));
		}

		printf("%lld\n", ans);

	}
	return 0;
}