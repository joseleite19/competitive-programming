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
			// if(tc == 14) printf("....%d %d\n", g[i], p);
			cnt[ g[i] % p ]++;
 		}

 		// printf("%d %d %d\n", cnt[0], cnt[1], cnt[2]);

		pass++;
		// ans++;
		ans += cnt[0];

		if(p == 4){
			ans += cnt[2] / 2;
			cnt[2] = 0;
			int tmp = min(cnt[1], cnt[3]);
			ans += tmp;
			cnt[1] -= tmp;
			cnt[3] -= tmp;
			if(cnt[1] != 0){
				ans += cnt[1] / p;
				cnt[1] %= p;
			}
			if(cnt[3] != 0){
				ans += cnt[3] / p;
				cnt[3] %= p;
			}
		}
		else if(p == 3){
			int tmp = min(cnt[1], cnt[2]);
			ans += tmp;
			cnt[1] -= tmp;
			cnt[2] -= tmp;
			if(cnt[1] != 0){
				ans += cnt[1] / p;
				cnt[1] %= p;
			}
			if(cnt[2] != 0){
				ans += cnt[2] / p;
				cnt[2] %= p;
			}
		}
		else if(p == 2){
			if(cnt[1] != 0){
				ans += cnt[1] / p;
				cnt[1] %= p;
			}
		}

		if(cnt[1] || cnt[2] || cnt[3])
			ans++;

		// ans += 1 + f(0, 0);

		printf("Case #%d: %d\n", tc, ans);
	}



	return 0;
}