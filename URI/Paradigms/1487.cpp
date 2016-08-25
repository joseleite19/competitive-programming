#include <bits/stdc++.h>

using namespace std;

int n, t, dp[605];

vector<pair<int,int> > v;

int f(int j){
	if(dp[j] != -1) return dp[j];

	int ans = 0;
	for(int i = 0; i < n; i++)
		if(j >= v[i].first)
			ans = max(ans, v[i].second + f(j - v[i].first));
	return dp[j] = ans;
}

int main(){

	int instancia = 1;

	while(scanf("%d %d", &n, &t) == 2, n){
		v.assign(n, pair<int,int>());
		for(int i = 0; i < n; i++)
			scanf("%d %d", &v[i].first, &v[i].second);
		memset(dp, -1, sizeof dp);
		printf("Instancia %d\n%d\n\n", instancia++, f(t));
	}

	return 0;
}