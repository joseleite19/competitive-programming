#include <bits/stdc++.h>

#define ff first
#define ss second

#define MOD 1000000007

using namespace std;

int sum[1003][26];
int cnt[1003];
int n;
char s[1003];

long long dp[1003][1003];
bool mark[1003][1003];

long long f(int i, int last){
	if(mark[i][last]) return dp[i][last];
	mark[i][last] = 1;

	long long &ans = dp[i][last];
	ans = 0;

	if(i == n) return ans = (last != n ? 1 : 0);

	ans += f(i+1, i);
	ans %= MOD;

	bool can = true;
	for(int j = 0; j < 26; j++){
		int tmp = sum[i][j] - (last > 0 ? sum[last-1][j] : 0);
		if(tmp > 0 && cnt[j] < i - last + 1)
			can = false;
		
	}

	if(can)
		ans += f(i+1, last);
	ans %= MOD;

	return ans;
}


long long pot(long long b, long long e){
	long long ans = 1;
	while(e){
		if(e & 1) ans = (ans * b) % MOD;
		b = (b * b) % MOD;
		e >>= 1;
	}
	return ans;
}

int main(){

	scanf("%d %s", &n, s);

	for(int i = 0; i < 26; i++)
		scanf("%d", cnt+i);

	sum[0][ s[0]-'a' ]++;

	for(int i = 1; i < n; i++){
		for(int j = 0; j < 26; j++)
			sum[i][j] = sum[i-1][j];
		sum[i][ s[i]-'a' ]++;
	}

	printf("%lld\n", (f(0, 0)*pot(2, MOD-2)) % MOD);

	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			bool can = true;
			for(int k = 0; k < 26; k++){
				int tmp = sum[j][k] - (i > 0 ? sum[i-1][k] : 0);
				if(tmp > 0 && cnt[k] < j - i + 1)
					can = false;
			}

			if(can) ans = max(ans, j - i + 1);
		}
	}

	printf("%d\n", ans);

	int q = 1, last = 0;

	for(int i = 0; i < n; i++){
		bool can = true;
		for(int k = 0; k < 26; k++){
			int tmp = sum[i][k] - (last > 0 ? sum[last-1][k] : 0);
			if(tmp > 0 && cnt[k] < i - last + 1)
				can = false;
		}
		if(!can){
			q++;
			last = i;
		}
	}

	printf("%d\n", q);




	return 0;
}