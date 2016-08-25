#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005], v[1005], n;

int f(int i, int j){
	if(dp[i][j] != -1) return dp[i][j];

	if(i == j) return 1;
	if(i+1 == j){
		if(v[i] == v[j]) return 1;
		return 2;
	}

	if(v[i] == v[j])
		return dp[i][j] = 1 + min(min(f(i+1, j-1), f(i+1, j)), f(i, j-1));
	return dp[i][j] = 1 + min(f(i+1, j), f(i, j-1));
}


int main(){
	int T;

	scanf("%d", &T);

	for(int t = 1; t <= T; t++){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", v + i);
		memset(dp, -1, sizeof dp);
		printf("Caso #%d: %d\n", t, f(0, n-1));
	}

	return 0;
}