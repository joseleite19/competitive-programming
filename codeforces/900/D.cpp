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
ll pot(ll b, int n){
	ll ans = 1;

	while(n){
		if(n & 1) ans = (ans * b) % MOD;
		b = (b * b) % MOD;
		n >>= 1;
	}
	return ans;
}

ll f(int x, int ja){
	if(x == 0) return ja == 1;
	ll ans = 0;
	for(int i = 1; i <= x; i++){
		ans += f(x - i, __gcd(ja, i));
		//if(x == 3) printf(".%d %lld\n", i, f(x - i));
	}
	return ans;
}

ll add(ll a, ll b){
	return a + b >= MOD ? a + b - MOD : a + b;
}

map<ll, ll> m;

ll f2(int x){
	if(x == 1) return 1;
	if(m.count(x)) return m[x];
	ll ans = add(pot(2, x-1), MOD-1);
	for(ll i = 2; i * i <= x; i++) if(x % i == 0){
		ans = add(ans, MOD - f2(x / i));
		if(i != x / i) ans = add(ans, MOD - f2(i));
	}
	return m[x] = ans;
}

ll e(int a){
	if(a < 2) return a;
	return e(a-1) + e(a-2);
}

ll c[4];
void mul(ll a[4], ll b[4]){
	c[0] = a[0] * b[0] + a[1] * b[2];
	c[1] = a[2] * b[0] + a[3] * b[2];
	c[2] = a[0] * b[1] + a[1] * b[3];
	c[3] = a[2] * b[1] + a[3] * b[3];
	forn(i, 4) a[i] = c[i] % MOD;
}

ll fib(int n){
	ll b[] = {1, 1, 1, 0}, ans[] = {1, 0, 0, 1};

	while(n){
		if(n & 1) mul(ans, b);
		mul(b, b);
		n >>= 1;
	}
	return ans[1];
}


int main(){

	int x, y;

	scanf("%d %d", &x, &y);

	if(y % x) return printf("0\n"), 0;

	y /= x;

	printf("%lld\n", f2(y));

	//printf("%lld\n", (pot(2, y-1) - fib(y-1) + MOD) % MOD);

	//for(int i = 1; i < 20; i++)
		//printf("%d %lld %lld\n", i, f(i, 0), f2(i));


    return 0;
}
