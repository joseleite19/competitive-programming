#include <bits/stdc++.h>

#define MOD (1000000007)

using namespace std;

int n;
char s[3005];
int mat[3005][2];

void calc(){
	mat[0][0] = mat[0][1] = 0;
	mat[0][ s[0]-'a' ] = 1;
	int j = 0;
	for(int i = 1; i < n; i++){
		mat[i][0] = mat[j][0];
		mat[i][1] = mat[j][1];
		mat[i][ s[i]-'a' ] = i+1;
		j = mat[j][ s[i]-'a' ];
	}
	mat[n][0] = mat[j][0];
	mat[n][1] = mat[j][1];
}


int dp[3003][3005];
int dp2[3003][3005];
int mark[3003][3005];
int mark2[3003][3005];
int pass;

// int f(int i, int state){
// 	if(i == 0) return mat[state][0];
// 	if(i == 1) return mat[state][1];
// 	if(mark[i][state] == pass) return dp[i][state];
// 	mark[i][state] = pass;

// 	int x = state;
// 	for(int j = i-1; j >= 0; j--)
// 		x = f(j, x);
// 	return dp[i][state] = f(i-1, x);
// }

// long long g(int i, int state){
// 	if(i == 0) return mat[state][0] == n;
// 	if(i == 1) return mat[state][1] == n;
// 	if(mark2[i][state] == pass) return dp2[i][state];
// 	mark2[i][state] = pass;

// 	long long &ans = dp2[i][state];
// 	ans = 0;
// 	int x = state;
// 	for(int j = i-1; j >= 0; j--){
// 		ans = (ans + g(j, x)) % MOD;
// 		x = f(j, x);
// 	}
// 	ans = (ans + g(i-1, x)) % MOD;

// 	return ans;
// }

int f(int i, int state){
	if(i == 1) return mat[state][0];
	if(i == 2) return mat[state][1];
	if(mark[i][state] == pass) return dp[i][state];
	mark[i][state] = pass;

	return dp[i][state] = f(i-2, f(i-1, state));
}

inline int add(int a, int b) {
	a += b;
	if(a >= MOD) {
		a -= MOD;
	}
	return a;
}

int g(int i, int state){
	if(i == 1) return mat[state][0] == n;
	if(i == 2) return mat[state][1] == n;
	if(mark2[i][state] == pass) return dp2[i][state];
	mark2[i][state] = pass;
	
	// int x = ;
	// int x = dp[i-1][state];
	// return dp2[i][state] = (g(i-1, state) + g(i-2, x)) % MOD;
	return dp2[i][state] = add(g(i-1, state), g(i-2, f(i-1, state)));
}

int main(){
	long long k;
	int m;

	scanf("%lld %d", &k, &m);

	for(int i = 0; i < m; i++){
		scanf(" %s", s);
		n = strlen(s);

		calc();

		// for(int state = 0; state <= n; state++){
		// 	dp[1][state] = mat[state][0];
		// 	dp[2][state] = mat[state][1];
		// }

		// for(int i = 3; i <= k; i++){
		// 	for(int state = 0; state <= n; state++){
		// 		int x = dp[i-1][state];
		// 		dp[i][state] = dp[i-2][x];
		// 	}
		// }

		pass++;
		printf("%d\n", g(k, 0));

// 		long long ans = 0;
// 		int state = 0;

// 		for(int i = 3003; i >= 0; i--){
// 			if((1LL << i) & k){
// 				ans = (ans + g(i, state)) % MOD;
// 				state = f(i, state);
// 			}
// 		}
// // g(k, 0)
// 		printf("%lld\n", ans);
	}

	return 0;
}