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

const int N = 100005;

ll dp[N][12];
int n, m;
char s[N], t[12];

ll f(int i, int j){
	if(j == m) return 1;
	if(i == n) return 0;
	ll &ans = dp[i][j];
	if(~ans) return ans;

	ans = f(i+1, j);
	if(s[i] == t[j]) ans = (ans + f(i+1, j+1)) % MOD;
	return ans;
}

int main(){

	scanf("%s %s", s, t);
	n = strlen(s), m = strlen(t);

	memset(dp, -1, sizeof dp);

	printf("%lld\n", f(0, 0));


    return 0;
}
