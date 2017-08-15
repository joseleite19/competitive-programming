#include <bits/stdc++.h>

using namespace std;

#define MOD (242121643)

void file(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
}

int v[200], n;

long long dp[200][200][2];
int mark[200][200][2], pass;

long long f(int i, int k, int bit){
	if(k == 0) return bit;
	if(i == n) return 0;

	if(mark[i][k][bit] == pass) return dp[i][k][bit];
	mark[i][k][bit] = pass;

	int tmp = bit;
	if(v[i] == 1) tmp++;
	tmp %= 2;
	return dp[i][k][bit] = (f(i+1, k-1, tmp) + f(i+1, k, bit)) % MOD;
}

int main(){
	file();

	int k;
	while(scanf("%d %d", &n, &k) && n+k){
		for(int i = 0; i < n; i++)
			scanf("%d", v+i);
		pass++;
		printf("%lld\n", f(0, k, 0));
	}

	return 0;
}
