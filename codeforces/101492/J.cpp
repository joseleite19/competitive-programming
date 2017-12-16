#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int vet[33], n;

int mark[33][1000][2], pass;
ll dp[33][1000][2];

ll F(int i, int sum, int less){
	if(i == n) return sum == 0;

	ll &ans = dp[i][sum][less];

	if(mark[i][sum][less] == pass) return ans;
	mark[i][sum][less] = pass;
	ans = 0;

	if(less){
		for(int d = 0; d < 10; d++){
			if(d <= sum){
				ans += F(i+1, sum-d, 1);
			}
		}
	}
	else{
		for(int d = 0; d < vet[i]; d++){
			if(d <= sum){
				ans += F(i+1, sum-d, 1);
			}
		}
		if(vet[i] <= sum)
			ans += F(i+1, sum-vet[i], 0);
	}
	return ans;
}

ll f(ll x, int block){
	ll ans = 0;
	{
		ll tmp = x;
		for(n = 0; tmp; n++, tmp /= 10)
			vet[n] = tmp % 10;

		reverse(vet, vet+n);
	}
	pass++;

	return ans + F(0, block, 0);
}

ll findpos(ll n, ll k){
	int block;

	{
		block = 0;
		ll tmp = k;
		while(tmp){
			block += tmp % 10;
			tmp /= 10;
		}
	}
	ll ans = 0;

	for(int i = 1; i < block; i++)
		ans += f(n, i);

	return ans + f(k, block);
}

ll findnum(ll n, ll k){
	int block;

	for(block = 1; ; block++){
		ll tmp = f(n, block);
		if(tmp < k) k -= tmp;
		else break; 
	}
	ll lo = 1, hi = 1e18+5;
	while(lo + 1 < hi){
		ll mid = (lo + hi) / 2;
		ll tmp = f(mid, block);
		if(tmp < k) lo = mid+1;
		else hi = mid;
	}
	if(f(lo, block) != k) lo = hi;
	return lo;
}

int main(){

	ll n, k;

	scanf("%lld %lld", &n, &k);

	ll ans1 = findpos(n, k);
	ll ans2 = findnum(n, k);

	printf("%lld %lld\n", ans1, ans2);


    return 0;
}
