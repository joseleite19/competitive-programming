#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

long long n, m;

long long dp[1000][1000];
long long dp2[1000][1000];

long long C(int n, int k){
	if(dp[n][k] != -1) return dp[n][k];
	if(n == k || n == 0 || k == 0) return 1;
	return dp[n][k] = C(n-1, k-1) + C(n-1, k);
}


long long h(int n, int k){
	if(k <= 0) return 0;
	if(n <= 0) return 0;
	if(k == 1) return n;
	if(dp2[n][k] != -1) return dp2[n][k];
	return dp2[n][k] = 1 + h(n-1, k-1) + h(n-1, k);
}


long long f(int x, int n){
	long long ans = 0;
	for(int k = 1; k <= x; k++)
		ans += C(n, k);
	return ans;
}

int main(){
	memset(dp, -1, sizeof dp);
	memset(dp2, -1, sizeof dp2);

	for(int i = 1; i <= 10; i++)
		printf("%lld %lld\n", f(i, 10), h(10, i));
		// printf("%lld %lld %lld\n", C(10, i), f(i, 10), C(11, i));



	


	return 0;
}