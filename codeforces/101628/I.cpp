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

const int N = 105;

inline ll add(ll a, ll b){
	return a + b >= MOD ? a + b - MOD : a + b;
}

inline ll mul(ll a, ll b){
	return (a * b) % MOD;
}

ll pot(ll b, ll e){
	ll ans = 1;
	while(e){
		if(e & 1) ans = mul(ans, b);
		b = mul(b, b);
		e >>= 1;
	}
	return ans;
}
int n;

struct mat{
	ll m[N][N];
	mat(){ memset(m, 0, sizeof m); }
	mat operator*(const mat &o) const{
		mat ans;
		forn(i, n) forn(j, n) forn(k, n)
			ans.m[i][j] = add(ans.m[i][j], mul(m[i][k], o.m[k][j]));
		return ans;
	}
};

int main(){
	int k;

	scanf("%d %d", &n, &k);

	mat x;

	forn(i, n) forn(j, n)
		scanf("%lld", &x.m[i][j]),
		x.m[i][j] = mul(x.m[i][j], pot(1000000, MOD-2));

	mat ans;

	forn(i, n) ans.m[i][i] = 1;

	while(k){
		if(k & 1) ans = ans * x;
		x = x * x;
		k >>= 1;
	}

	ll r = 0;

	forn(i, n)
		r = add(r, mul(i+1, ans.m[0][i]));

	printf("%lld\n", r);





    return 0;
}
