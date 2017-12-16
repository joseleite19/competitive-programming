#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, g[200], p, v[200];
int dp[200][200];
int mark[200][200], pass;

int f(int i, int sum){
	if(i == n) return 0;
	if(mark[i][sum] == pass) return dp[i][sum];
	mark[i][sum] = pass;

	return dp[i][sum] = max(max(f(i+1, sum), ((sum + v[i]) % p == 0) + f(i+1, (sum+v[i])%p)), f(i+1, v[i]));
}


int main(){
	int t;

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		scanf("%d %d", &n, &p);
		for(int i = 0; i < n; i++)
			scanf("%d", g+i);

		int ans = 0;
		int cnt[4];
		for(int i = 0; i < 4; i++) cnt[i] = 0;

		for(int i = 0; i < n; i++){
			cnt[ g[i] % p ]++;
 		}

		pass++;
		// ans++;
		ans += cnt[0];
		if(cnt[1] || cnt[2])
			ans++;

		if(p == 3){
			ans += min(cnt[1], cnt[2]);
			int tmp = min(cnt[1], cnt[2]);
			cnt[1] -= tmp;
			cnt[2] -= tmp;
			ans += cnt[1] / p + cnt[2] / p - (cnt[1] % p == 0) - (cnt[2] % p == 0);
		}
		else if(p == 2){
			ans += cnt[1] / p - (cnt[1] % p == 0);
		}

		// ans += 1 + f(0, 0);

		printf("Case #%d: %d\n", tc, ans);
	}



	return 0;
}