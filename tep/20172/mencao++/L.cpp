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

const int N = 5000006;

ll lp[N], dp[N];

ll f(int n){
	if(n == 1) return 0;
	if(~dp[n]) return dp[n];
	return dp[n] = (n * (lp[n] - 1) / 2 + f(n / lp[n])) % MOD;
}

int main(){
	memset(dp, -1, sizeof dp);

	for(int i = 2; i < N; i++) if(!lp[i]){
		for(int j = i; j < N; j += i) if(!lp[j])
			lp[j] = i;
	}

	int t, l, r;
	scanf("%d %d %d", &t, &l, &r);

	ll ans = 0, b = 1;

	fore(i, l, r+1){
		ans = (ans + b * f(i)) % MOD;
		b = (b * t) % MOD;
	}

	printf("%lld\n", ans);


    return 0;
}
