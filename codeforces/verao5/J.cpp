#include <bits/stdc++.h>

#define MOD (1000000007)

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

long long n;

long long v[100005];

long long fat[400005];

long long pot(long long b, long long e){
	long long ans = 1;

	while(e){
		if(e & 1) ans = (ans * b) % MOD;
		b = (b * b) % MOD;
		e >>= 1;
	}
	return ans;
}

long long C(long long int n, long long int k){
	long long tmp = (fat[n] * pot(fat[k], MOD-2)) % MOD;
	tmp = (tmp * pot(fat[n-k], MOD-2)) % MOD;
	return tmp;
}

int main(){

	fat[0] = 1LL;
	for(long long i = 1; i < 400005; i++)
		fat[i] = (fat[i-1]*i) % MOD;

	// for(int i = 0; i < 10; i++)
	// 	printf("%d %lld\n", i, fat[i]);

	scanf("%lld", &n);

	for(long long i = 0; i < n; i++)
		scanf("%lld", v+i);

	long long ans = 1;
	long long tmp = 0;

	for(long long i = 0; i < n; i++)
		tmp += v[i]-1;

	if(tmp != n-2){
		printf("0\n");
		return 0;
	}

	// printf("..%lld\n", tmp);

	for(long long i = 0; i < n; i++){
		// printf("(%lld, %lld) = %lld\n", tmp, v[i]-1, C(tmp, v[i]-1));
		ans = (ans * C(tmp, v[i]-1)) % MOD;
		tmp -= (v[i]-1);
	}

	// ans = fat[n-2];

	// for(long long i = 0; i < n; i++)
	// 	if(v[i] == 3)
	// 		ans = (ans * pot(2, MOD-2)) % MOD;

	// ans = (ans * pot(2, MOD-2)) % MOD;

	printf("%lld\n", ans);

	return 0;
}