#include <bits/stdc++.h>

using namespace std;

int dp[1005], k;

vector<pair<int, pair<int, int>>> v;

int f(int t){
	if(t > k) return 0;
	if(dp[t] != -1) return dp[t];
	int ans = 0;
	for(int j = t + 1; j <= k; j++)
		if(max(abs(v[t].second.first - v[j].second.first), abs(v[t].second.second - v[j].second.second)) <= v[j].first - v[t].first)
			ans = max(ans, 1 + f(j));

	return dp[t] = ans;
}

int main(){
	int n, m, x, y;

	while(scanf("%d %d %d", &n, &m, &k) == 3 && n + m + k){
		v.assign(k+1, pair<int,pair<int,int>>());
		for(int i = 1; i <= k; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			v[i] = {c, {a, b}};
		}

		scanf("%d %d", &x, &y);

		v[0] = {0, {x, y}};

		memset(dp, -1, sizeof dp);

		printf("%d\n", f(0));
	}

	return 0;
}