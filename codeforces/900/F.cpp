#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ford(i, n) for(int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;

const int N = 100005;

ll dp[1005][1005];

ll C(int n, int k){
	if(n == 0 || k == 0 || n == k) return 1;
	if(dp[n][k]) return dp[n][k];
	return dp[n][k] = C(n-1, k) + C(n-1,k-1);
}

int main(){

	for(int n = 1; n < 9; n++){
		int m = 9 - n;
		ll ans = 0;
		for(int i = max(n, m); i < n+m; i++)
			ans += C(n*m, i);
		printf("%d %d %lld\n", n, m, ans);
	}

    return 0;
}
