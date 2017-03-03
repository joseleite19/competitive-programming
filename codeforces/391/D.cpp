#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD 1000000007

using namespace std;

char v[22][10] = { "0",
				   "1",
				   "10",
				   "11",
				   "100",
				   "101",
				   "110",
				   "111",
				   "1000",
				   "1001",
				   "1010",
				   "1011",
				   "1100",
				   "1101",
				   "1110",
				   "1111",
				   "10000",
				   "10001",
				   "10010",
				   "10011",
				   "10100",
				   "10101",
				};

long long dp[100][100][30];
char b[100];
int n;

int cmp(int i, int k){
	int m = strlen(v[k]), j;
	if(i + m - 1 >= n) return -1;

	for(j = 0; j < m; j++)
		if(v[k][j] != b[i+j])
			return -1;

	return i + m-1;
}

int cmp2(int i, int k){
	int m = strlen(v[k]);
	if(i - m + 1 < 0) return -1;
	int j;

	for(int j = 0; j < m; j++){
		if(v[k][m-1-j] != b[i-j])
			return -1;
	}
	return i - m+1;
}

long long f(int L, int R, int k){
	long long &ret = dp[L][R][k];
	printf("%d %d %d\n", L, R, k);
	if(ret != -1) return ret;
	ret = 1;

	for(int K = 1; K < k; K++){
		int r = R+1;
		while(r < n && b[r] == '0') r++;
		
		if(r < n){
			r = cmp(r, K);
			if(r != -1) ret += f(L, r, k);
		}

		ret %= MOD;
		int l = cmp2(L-1, K);
		if(l != -1) ret += f(l, R, k);
		ret %= MOD;
	}

	int r = R+1;
	while(r < n && b[r] == '0') r++;
	
	if(r < n){
		r = cmp(r, k);
		if(r != -1) ret += f(L, r, k+1);
	}

	ret %= MOD;

	int l = cmp2(L-1, k);
	if(l != -1) ret += f(l, R, k+1);
	ret %= MOD;

	return ret;
}

int main(){

	scanf("%d %s", &n, b);

	memset(dp, -1, sizeof dp);
	long long ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			int l = i;
			while(l < j && b[l] == '0') l++;

			if(l == j && b[j] == '1'){
				ans = (ans + f(i, j, 2)) % MOD;
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
}