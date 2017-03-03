#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000000000000
#define MOD 1000000007

using namespace std;

int n, r[2003], m;

int fat[2003];
int inv[2003];

int exp(int n){
	int e = MOD-2;
	int ans = 1;
	while(e){
		if(e & 1) ans = (1LL * ans * n) % MOD;
		n = (1LL * n * n) % MOD;
		e >>= 1;
	}
	return ans;
}

map<pair<int, int>, int> d;

int C(int n, int k){
	if(n < 0) return 0;
	if(n < k) return 0;
	if(n == k || k == 0) return 1;
	if(d.count(mp(n, k))) return d[mp(n, k)];

	int ans = 1;
	for(int i = n; i >= n-k+1; i--){
		ans = (1LL * ans * i) % MOD;
	}
	return d[mp(n, k)] = (1LL * ans * inv[k]) % MOD;
}

int solve(){
	d.clear();

	int all = 0;
	for(int i = 0; i < n; i++)
		all += r[i];

	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			int left = m - 2*(all - r[i] - r[j]) - r[i] - r[j];
			ans = (ans + 2LL*C(left-1 + n-1, left)) % MOD;
		}
	}
	
	for(int i = 0; i < n; i++){
		int left = m - 2*(all - r[i]) - r[i];
		ans = (ans + 2LL*C(left-1 + n, left)) % MOD;
		printf("asd %d %d\n", ans, left);
	}

	int left = m - 2*(all);
	ans = (ans + 2LL*C(left-1 + n+1, left)) % MOD;

	return ans;
}


int main(){
	int t;


	fat[0] = 1;
	for(int i = 1; i < 2003; i++)
		fat[i] = (1LL * i * fat[i-1]) % MOD;

	for(int i = 0; i < 2003; i++)
		inv[i] = exp(fat[i]);

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		scanf("%d %d", &n, &m);

		for(int i = 0; i < n; i++)
			scanf("%d", r+i);

		printf("Case #%d: %d\n", tc, solve());
	}

	return 0;
}