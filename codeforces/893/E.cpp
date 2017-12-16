#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define MOD 1000000007
#define ford(i, n) for(int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;

const int N = 2000006;

ll fat[N], lp[N];

ll pot(ll b, ll e){
	ll ans = 1; b %= MOD;
	while(e){
		if(e & 1) ans = (ans * b) % MOD;
		b = (b * b) % MOD;
		e >>= 1;
	}
	return ans;
}

ll C(int n, int k){
	return (fat[n] * pot(fat[k] * fat[n-k], MOD-2)) % MOD;
}

ll f(int x, int y){
	ll ans = 1;

	while(x > 1){
		int cnt = 0, l = lp[x];
		while(lp[x] == l) cnt++, x /= lp[x];
		ans = (ans * C(y + cnt - 1, cnt)) % MOD;
	}
	ans = (ans * pot(2, y-1)) % MOD;
	return ans;
}

int main(){
	fat[0] = 1;
	fore(i, 1, N) fat[i] = (i * fat[i-1]) % MOD;

	lp[1] = 1;
	fore(i, 2, N) if(!lp[i]){
		for(int j = i; j < N; j += i) if(!lp[j])
			lp[j] = i;
	}

	int t, x, y;
	scanf("%d", &t);

	while(t--){
		scanf("%d %d", &x, &y);
		printf("%lld\n", f(x, y));
	}


    return 0;
}
