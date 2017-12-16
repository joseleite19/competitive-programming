#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000006;

char t[N], p[N];
int n, m, k;

int dp[N][105];
bool mark[N][105];

int main(){

	scanf("%d %d %d %s %s", &m, &n, &k, p, t);

	if(k >= m) return printf("S\n"), 0;

	for(int j = 0; j < m; j++)
		dp[n][j] = m - j;

	for(int i = n-1; i >= 0; i--){
		for(int j = m-1; j >= 0; j--){
			if(t[i] == p[j]) dp[i][j] = dp[i+1][j+1];
			else dp[i][j] = 1 + min(min(dp[i+1][j+1], dp[i+1][j]), dp[i][j+1]);
		}
	}

	bool ans = 0;

	for(int i = 0; i < n; i++)
		if(dp[i][0] <= k)
			ans = 105;

	printf("%s\n", ans ? "S" : "N");


    return 0;
}
