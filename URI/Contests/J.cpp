#include <bits/stdc++.h>

using namespace std;

long long dp[20];

long long pot(int n){
	long long ans = 1;
	for(int i = 0; i < n; i++)
		ans *= 10;
	return ans;
}

long long f(int i, int b){
	if(i <= 1) return 0;
	if(b) return 45*pot(i-2) + 10*f(i-2, 1);
	else return 36*pot(i-2) + 9*f(i-2, 1);
}

int main(){
	int k;

	scanf("%d", &k);
	printf("%lld\n", f(k, 0));

	return 0;
}