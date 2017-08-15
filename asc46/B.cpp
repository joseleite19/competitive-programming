#include <bits/stdc++.h>

#define MOD (175781251)

using namespace std;

void file(){
	freopen("bipartite.in", "r", stdin);
	freopen("bipartite.out", "w", stdout);
}

long long fat[20004];

long long g(long long b, long long e){
	b %= MOD;
	long long ans = 1;
	while(e){
		if(e & 1) ans = (ans * b) % MOD;
		b = (b * b) % MOD;
		e >>= 1;
	}
	return ans;
}

long long C(long long n, long long k){
	if(k < 0) return 0;
	if(n < 0) return 0;
	if(n == k || k == 0 || n == 0) return 1;
	return (fat[n] * g(fat[k] * fat[n-k], MOD-2)) % MOD;
}

bool check(int x){
	if((x & 7) == 7) return false;
	if((x & 49) == 49) return false;
	if((x & 44) == 44) return false;
	if((x & 26) == 26) return false;
	return true;
}

long long f(long long v, long long e){
	return (C(v*(v-1)/2, e) - C(v, 3) * C(v*(v-1)/2 - 3, e - 3)) % MOD;
}



long long calc(long long n){
	if(n == 1) return 1;
	if(n == 2) return 3;
	long long ans = 0;

	for(int i = 0; i <= n*(n-1)/2; i++){
		long long tmp = (g(2, i) * f(n, i)) % MOD;
		if(tmp < 0) break;
		ans = (ans + tmp) % MOD;
	}
	return ans;
}

int main(){
	file();

	fat[0] = 1;
	for(int i = 1; i < 20004; i++)
		fat[i] = (i*fat[i-1]) % MOD;

	long long n;

	// int cnt = 0, q = 0;

	// int w[10] = {0};
	// for(int bit = 0; bit < (1 << 6); bit++){
	// 	if(check(bit)){
	// 		cnt += 1 << __builtin_popcount(bit);
	// 		q++;
	// 		w[__builtin_popcount(bit)]++;
	// 		// cnt++;
	// 	}
	// }

	// printf("%d %d\n", cnt, q);
	// for(int i = 0; i <= 6; i++)
	// 	printf("%d %d\n", i, w[i]);



	while(scanf("%lld", &n) == 1 && n){
		printf("%lld\n", calc(n));
	}

	return 0;
}