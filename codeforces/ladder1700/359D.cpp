#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int n, v[300005];

int g[1000006];

int dp[300005][20];

int f(int i, int j){
	if(j == 0) return v[i];
	if(dp[i][j] != -1) return dp[i][j];
	return dp[i][j] = gcd(f(i, j-1), f(i + (1 << (j-1)), j-1));
}

int query(int i, int j){
	int len = j-i+1;
	int lg = 31 - __builtin_clz(len);
	return gcd(f(i, lg), f(j-(1<<lg)+1, lg));
}

int main(){
	memset(dp, -1, sizeof dp);

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	int best = 0;
	for(int i = 0; i < n; i++){
		int L = i, R = i;
		int lo, hi;

		lo = i, hi = n-1;
		while(lo <= hi){
			int mid = (lo+hi)/2;

			if(query(i, mid) == v[i]) lo = mid+1;
			else hi = mid-1;
		}
		R = lo-1;

		lo = 0, hi = i;
		while(lo <= hi){
			int mid = (lo+hi)/2;

			if(query(mid, i) == v[i]) hi = mid-1;
			else lo = mid+1;
		}
		L = lo;

		L++; R++;

		g[L] = max(g[L], R);
		best = max(best, R - L);
	}

	vector<int> ans;
	for(int L = 1; L < 1000006; L++)
		if(g[L] - L == best)
			ans.push_back(L);

	printf("%d %d\n", (int)ans.size(), best);
	for(int i = 0; i < (int)ans.size(); i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}