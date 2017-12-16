#include <bits/stdc++.h>

using namespace std;

int dp[1000006], v[1000006], n;

int f(int i){
	if(i >= n) return 0;
	if(dp[i] != -1) return dp[i];

	return dp[i] = max(v[i] + f(i+3), f(i+1));
}

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v + i);

	memset(dp, -1, sizeof dp);
	printf("%d\n", f(0));

	return 0;
}