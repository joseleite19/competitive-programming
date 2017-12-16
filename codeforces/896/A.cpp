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
const ll MAX = 1e18+9;

ll dp[N];

ll sz(int n){
	if(n == 0) return 75;
	if(~dp[n]) return dp[n];
	return dp[n] = min(MAX, 2*sz(n-1) + 68);
}

char s0[] = "What are you doing at the end of the world? Are you busy? Will you save us?";
char s1[] = "What are you doing while sending \"";
char s2[] = "\"? Are you busy? Will you send \"";

char f(int n, ll k){
	if(k >= sz(n)) return '.';
	if(n == 0){
		if(k < sz(0)) return s0[k];
		return '.';
	}
	if(k < 34) return s1[k];
	k -= 34;
	if(k < sz(n-1)) return f(n-1, k);
	k -= sz(n-1);
	if(k < 32) return s2[k];
	k -= 32;
	if(k < sz(n-1)) return f(n-1, k);
	k -= sz(n-1);
	if(k < 2) return "\"?"[k];
	return '.';
}

int main(){
	memset(dp, -1, sizeof dp);

	int n, q;

	ll k;

	scanf("%d", &q);

	while(q--){
		scanf("%d %lld", &n, &k);
		printf("%c", f(n, k-1));
	}

	printf("\n");

    return 0;
}
