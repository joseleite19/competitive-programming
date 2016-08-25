#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> dp[205][205][205];
int n, l1, l2, l3, s1[205], s2[205], s3[205];
int after[3][205][22];

#define INF 1000000000000000000

pair<long long, long long> f(int i, int j, int k){
	if(i > l1 || j > l2 || k > l3) return {0, 1};
	if(i == l1 || j == l2 || k == l3) return dp[i][j][k] = {0, 1};
	if(dp[i][j][k].first != -1) return dp[i][j][k];

	pair<long long, long long> ans = {INF, INF};
	for(int ii = 1; ii <= n; ii++){
		auto tmp = f(after[0][i][ii]+1, after[1][j][ii]+1, after[2][k][ii]+1);
		if(1 + tmp.first < ans.first) ans = {tmp.first + 1, tmp.second};
		if(1 + tmp.first == ans.first){
			printf("{%lld, %lld} {%lld, %lld}\n", ans.first, ans.second, tmp.first, tmp.second);
			ans = {ans.first, ans.second + tmp.second};
		}
	}
	return dp[i][j][k] = ans;
}

int main(){

	scanf("%d %d %d %d", &n, &l1, &l2, &l3);

	printf("%d\n", l1);
	for(int i = 0; i < l1; i++)
		scanf("%d", s1 + i);
	
	for(int i = 0; i < l2; i++)
		scanf("%d", s2 + i);
	
	for(int i = 0; i < l3; i++)
		scanf("%d", s3 + i);

	memset(after, -1, sizeof after);
	for(int i = 0; i < l1; i++){
		for(int k = 1; k <= n; k++){
			for(int j = i; j < l1; j++)
				if(s1[j] == k && after[0][i][k] == -1)
					after[0][i][k] = j;
			if(after[0][i][k] == -1)
				after[0][i][k] = l1;
		}
	}
	for(int i = 0; i < l2; i++){
		for(int k = 1; k <= n; k++){
			for(int j = i; j < l2; j++)
				if(s2[j] == k && after[1][i][k] == -1)
					after[1][i][k] = j;
			if(after[1][i][k] == -1)
				after[1][i][k] = l2;
		}
	}
	for(int i = 0; i < l3; i++){
		for(int k = 1; k <= n; k++){
			for(int j = i; j < l3; j++)
				if(s3[j] == k && after[2][i][k] == -1)
					after[2][i][k] = j;
			if(after[2][i][k] == -1)
				after[2][i][k] = l3;
		}
	}

	for(int i = 1; i <= n; i++){
		after[0][l1][i] = l1;
		after[1][l2][i] = l2;
		after[2][l3][i] = l3;
	}

	memset(dp, -1, sizeof dp);

	pair<long long, long long> ans = f(0, 0, 0);
	printf("%lld %lld\n", ans.first, ans.second);

	// for(int i = 0; i <= l1; i++){
	// 	printf("%d\n", i);
	// 	for(int j = 0; j <= l2; j++){
	// 		for(int k = 0; k <= l3; k++){
	// 			printf("{%lld, %lld} ", dp[i][j][k].first, dp[i][j][k].second);
	// 		}
	// 		printf("\n");
	// 	}
	// 	printf("\n");
	// }

	return 0;
}