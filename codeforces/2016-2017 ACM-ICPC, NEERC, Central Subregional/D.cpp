#include <bits/stdc++.h>

#define MOD (1000000007)

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

char s[100005];

long long dp[100005];
long long mark[100005];
int n;

long long f(int i){
	if(i == n) return 1;
	
	if(mark[i]) return dp[i];
	mark[i] = 1;

	long long &ans = dp[i];
	ans = f(i+1);
	if(s[i] == 'N' && (s[i+1] == 'E' || s[i+1] == 'W')) ans = (ans + f(i+2)) % MOD;
	if(s[i] == 'S' && (s[i+1] == 'E' || s[i+1] == 'W')) ans = (ans + f(i+2)) % MOD;

	return ans;
}



int main(){
	// file();
	scanf("%s", s);

	n = strlen(s);

	printf("%lld\n", f(0));

	return 0;
}