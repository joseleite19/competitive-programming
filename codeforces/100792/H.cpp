#include <bits/stdc++.h>

using namespace std;

int n, a[100005];
long long dp[2][257];

int main(){
	
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%x", a + i);

	memset(dp, 0, sizeof dp);

	for(int i = n-1; i >= 0; i--){
		if(i & 1)
			for(int j = 0; j < 257 && i >= j; j++)
				dp[1][j] = max(dp[0][j+1], dp[0][j] + (a[i]^(i-j)));
		else
			for(int j = 0; j < 257 && i >= j; j++)
				dp[0][j] = max(dp[1][j+1], dp[1][j] + (a[i]^(i-j)));
	}

	printf("%lld\n", dp[0][0]);

	return 0;
}