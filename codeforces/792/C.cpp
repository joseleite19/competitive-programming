#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

#define oo (10000000)

using namespace std;

int dp[100005][2][3];
int mark[100005][2][3];
int n;
char s[100005];

int f(int i, int zero, int sum){
	if(mark[i][zero][sum]) return dp[i][zero][sum];
	mark[i][zero][sum] = 1;

	if(i == n){
		if(sum) return dp[i][zero][sum] = -oo;
		if(!zero) return dp[i][zero][sum] = -oo;

		return dp[i][zero][sum] = 0;
	}

	if(!s[i] && !zero) return dp[i][zero][sum] = f(i+1, zero, sum);
	return dp[i][zero][sum] = max(f(i+1, zero, sum), 1+f(i+1, zero || s[i], (sum + s[i]) % 3));
}

int main(){

	scanf("%s", s);
	n = strlen(s);

	for(int i = 0; i < n; i++)
		s[i] -= '0';

	if(f(0, 0, 0) < 0){
		for(int i = 0; i < n; i++)
			if(s[i] == 0){
				printf("0\n");
				return 0;
			}
		printf("-1\n");
		return 0;
	}

	int zero = 0, sum = 0;
	for(int i = 0; i < n; i++){
		if(!s[i] && !zero) continue;

		if(f(i+1, zero, sum) <= 1+f(i+1, zero || s[i], (sum + s[i]) % 3)){
			printf("%d", s[i]);
			zero = zero || s[i];
			sum = (sum + s[i]) % 3;
		}
	}
	printf("\n");


	return 0;
}