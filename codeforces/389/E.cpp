#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, v[1000006];

long long k, dp[10000007];

bool f(long long mid){
	for(int i = 0; i < mid; i++) dp[i] = 0;
	for(int i = mid; i < 10000007; i++)
		dp[i] = max(1LL, dp[i/2] + dp[i/2 + (i&1)]);

	long long sum = 0;
	for(int i = 0; i < n; i++){
		sum += dp[ v[i] ];
		if(sum >= k) return 1;
	}
	return 0;
}

int main(){

	scanf("%d %lld", &n, &k);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	long long sum = 0;
	for(int i = 0; i < n; i++)
		sum += v[i];

	if(sum < k){
		printf("-1\n");
		return 0;
	}

	long long hi, lo;
	lo = 1;
	hi = 10000000;

	while(lo+1 < hi){
		long long mid = (lo + hi)/2;
		if(f(mid)) lo = mid;
		else hi = mid-1;
	}
	if(!f(hi)) hi--;

	printf("%lld\n", hi);

	return 0;
}