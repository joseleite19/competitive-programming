#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);
}

long long dp[100005][2];
bool mark[100005][2];

bool f(int n, bool who){
	if(mark[n][who]) return dp[n][who];
	mark[n][who] = 1;

	int lim = sqrt(n);
	for(int i = 1; i <= lim; i++){
		if(f(n - i, !who) != who){
			return dp[n][who] = !who;
		}
	}

	return dp[n][who] = who;
}

int main(){
	long long n;

	// for(int i = 1; i < 400; i++)
	// 	if(!f(i, 0))
	// 		printf("%d = %d\n", i, f(i, 0));
	scanf("%lld", &n);

	if(n == 1){
		printf("WIN\n");
		return 0;
	}
	if(n == 2){
		printf("LOSE\n");
		return 0;
	}

	long long tmp = 2, add = 3;

	while(1){

		tmp += add;
		if(tmp == n){
			printf("LOSE\n");
			return 0;
		}
		if(add & (add - 1)){
			tmp += add;
		}

		if(tmp == n){
			printf("LOSE\n");
			return 0;
		}


		add++;
		if(tmp > n) break;
	}

	printf("WIN\n");

	// bool win = false;

	// while(n){
	// 	long long w = sqrt(n);
	// 	n -= w;
	// 	win ^= 1;
	// }


	// printf("%s\n", f(n, 0) ? "WIN" : "LOSE");


	return 0;
}