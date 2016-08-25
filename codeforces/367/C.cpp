#include <bits/stdc++.h>

#define oo 1000000000000000000

using namespace std;

string s[100005];
string r[100005];
int n, c[100005];

long long dp[2];

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", c+i);

	for(int i = 0; i < n; i++)
		cin >> s[i], r[i] = s[i], reverse(r[i].begin(), r[i].end());

	dp[0] = dp[1] = 0;

	long long tmp, tmp1;
	for(int x = n-1; x > 0; x--){
		tmp = oo;
		if(s[x] >= r[x-1]) tmp = min(tmp, dp[0]);
		if(r[x] >= r[x-1]) tmp = min(tmp, c[x]+dp[1]);

		tmp1 = oo;
		if(s[x] >= s[x-1]) tmp1 = min(tmp1, dp[0]);
		if(r[x] >= s[x-1]) tmp1 = min(tmp1, c[x]+dp[1]);

		dp[0] = tmp1, dp[1] = tmp;
	}

	long long ans = min(c[0] + dp[1], dp[0]);

	printf("%lld\n", ans == oo ? -1 : ans);

	return 0;
}