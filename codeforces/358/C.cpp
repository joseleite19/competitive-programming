#include <bits/stdc++.h>

int n, m, k;
int dp[1005][1005][15][2];

char s[1005], t[1005];
using namespace std;
int f(int i, int j, int q, int state){
	// printf("%d %d..\n", i, j);
	if(i == n || j == m || q == k) return 0;
	if(dp[i][j][q][state] != -1) return dp[i][j][q][state];

	int nextMis = state ? q + 1 : q;
	if(s[i] == t[j])
		return dp[i][j][q][state] = max(max(1 + f(i+1, j+1, q, 1), f(i+1, j, nextMis, 0)), f(i, j+1, nextMis, 0));

	return dp[i][j][q][state] = max(f(i+1, j, nextMis, 0), f(i, j+1, nextMis, 0));
}

int main(){
	scanf("%d %d %d %s %s", &n, &m, &k, s, t);

	memset(dp, -1, sizeof dp);
	printf("%d\n", f(0, 0, 0, 0));

	return 0;
}