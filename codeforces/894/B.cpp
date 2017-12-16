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

const int N = 1005;

int mat[N][N];
int k, ans;

ll n, m;

void f(int i, int j){
	if(i == n){
		int t = 1;
		forn(i, n){
			t = 1;
			forn(j, m){
				t *= mat[i][j];
			}
			if(t != k) return;
		}
		forn(j, m){
			t = 1;
			forn(i, n) t *= mat[i][j];
			if(t != k) return;
		}
		ans++;
	}
	else if(j == m) f(i+1, 0);
	else{
		mat[i][j] = 1;
		f(i, j+1);
		mat[i][j] = -1;
		f(i, j+1);
	}
}

ll pot(ll b, ll e){
	ll ans = 1; b %= MOD;
	while(e){
		if(e & 1) ans = (ans * b) % MOD;
		b = (b * b) % MOD;
		e >>= 1;
	}
	return ans;
}

int main(){

	scanf("%lld %lld %d", &n, &m, &k);
	/*k = -1;

	for(n = 1; n < 7; n++){
		for(m = n; m < 7; m++){
			ans = 0;
			f(0, 0);
			printf("%lld %lld %d\n", n, m, ans);
		}
	}*/

	printf("%lld\n", !~k && (n & 1)^(m & 1) ? 0 :  pot(pot(2, n-1), m-1));

    return 0;
}
