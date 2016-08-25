#include <bits/stdc++.h>

using namespace std;

vector<int> g;
int r, k, dp[105][10101];

int f(int i, int qnt){
	if(qnt == k) return 1;
	if(i == r || qnt > k) return 0;
	if(dp[i][qnt] != -1) return dp[i][qnt];

	return dp[i][qnt] = max(f(i+1, qnt), f(i+1, qnt + g[i]));
}

int main(){

	while(scanf("%d %d", &r, &k) == 2){
		g.assign(r+1, 0);
		for(int i = 0, a, b; i < k; i++){
			scanf("%d %d", &a, &b);
			g[a-1]++;
			g[b-1]++;
		}

		memset(dp, -1, sizeof dp);
		printf("%c\n", f(0, 0) == 1 ? 'S' : 'N');
	}
	return 0;
}