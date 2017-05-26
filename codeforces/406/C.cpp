#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

// 0 - win; 1 - lose; 3 = loop

int n, k[2], s[2][7003];

char dp[7003][7003][2];

// 0 = eu, 1 = outro
// 0 = ganho, 1 perdo, 2 loop
int f(int x, int used, int j){
	if(x == 0){
		return dp[x][used][j] = 1;
	}
	if(used == 0){
		return dp[x][used][j] = 2;
	}
	if(dp[x][used][j] != -1) return dp[x][used][j];
	// mark[x][j] = 1;

	int ans = 0;

	if(j == 0){
		ans = 1;
		for(int i = 0; i < k[j]; i++){
			int tmp = f((x + s[j][i]) % n, used-1, 1-j);
			if(tmp == 1){
				ans = 0;
				// ans = min(ans, 0);
			}
			else if(tmp == 2){
				if(ans == 1) ans = 2;
			}
			else if(tmp == 0){
				// ans = min(ans, 1);
			}
		}
		// int tmp = f(x, used-1, j);
		// if(tmp == 0) ans = 0;
		// else if(tmp == 2 && ans == 1) ans = 2;
	}
	else{
		ans = 1;
		for(int i = 0; i < k[j]; i++){
			int tmp = f((x + s[j][i]) % n, used-1, 1-j);
			if(tmp == 1){
				ans = 0;
				// ans = max(ans, 0);
			}
			else if(tmp == 2){
				if(ans == 1) ans = 2;
				// ans = max(ans, 2);
			}
			else if(tmp == 0){
				// ans = max(ans, 1);
			}
		}
		// int tmp = f(x, used-1, j);
		// if(tmp == 0) ans = 0;
		// else if(tmp == 2 && ans == 1) ans = 2;
	}


	// if(j) ans = 1;
	// for(int i = 0; i < k[j]; i++){
	// 	if(j == 0){

	// 	}
	// 	else{

	// 	}
	// 	if(!j) ans |= f((x + s[j][i]) % n, used-1, 1-j);
	// 	else  ans &= f((x + s[j][i]) % n, used-1, 1-j);
	// }
	// if(!j) ans |= f(x, used-1, j);
	// else   ans &= f(x, used-1, j);

	return dp[x][used][j] = ans;
}

int main(){
	memset(dp, -1, sizeof dp);

	scanf("%d", &n);

	for(int i = 0; i < 2; i++){
		scanf("%d", k+i);
		for(int j = 0; j < k[i]; j++){
			scanf("%d", &s[i][j]);
		}
	}

	// printf("%d\n", f(1, n, 0));

	for(int i = 1; i < n; i++){
		int tmp = f(i, n+2, 0);
		if(tmp == 1) printf("Lose ");
		else if(tmp == 0) printf("Win "); 
		else printf("Loop ");
	}
	printf("\n");

	// {
	// 	int tmp[7003];
	// 	for(int i = 0; i < k[0]; i++)
	// 		tmp[i] = s[0][i];
	// 	for(int i = 0; i < 7002; i++)
	// 		swap(s[1][i], tmp[i]);
	// 	for(int i = 0; i < k[1]; i++)
	// 		s[0][i] = tmp[i];
	// 	swap(k[0], k[1]);
	// }

	for(int i = 1; i < n; i++){
		int tmp = f(i, n+2, 1);
		if(tmp == 1) printf("Lose ");
		else if(tmp == 0) printf("Win "); 
		else printf("Loop ");
	}
	printf("\n");

	return 0;
}