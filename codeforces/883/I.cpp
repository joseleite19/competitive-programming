#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i < int(b); i++)

using namespace std;

typedef long long ll;

const int N = 300005;

int v[N], n, k, dp[N];

int f(int val){
	memset(dp, 0, sizeof dp);

	dp[0] = 1;
	int cnt = 1, l = 1;
	fore(i, 1, n+1){
		while(v[i] - v[l] > val) cnt -= dp[l-1], l++;
		if(l <= i-k+1) dp[i] = cnt > 0;
		if(i-k+1 > 0) cnt += dp[i-k+1] > 0;
	}
	return dp[n] > 0;
}

int main(){

	scanf("%d %d", &n, &k);

	if(k == 1) return printf("0\n"), 0;

	fore(i, 1, n+1) scanf("%d", v+i);

	sort(v+1, v+n+1);

	int L = 0, R = 1e9+2;

	while(L < R){
		int mid = (L+R)/2;
		if(f(mid)) R = mid;
		else L = mid+1;
	}

	printf("%d\n", L);



	return 0;
}

