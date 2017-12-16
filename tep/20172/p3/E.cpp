#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define debug(x) cout << #x << " = " << x << endl
#define ford(i, a, b) for(int i = a; i >= b; i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 100005;

inline void madd(ll &a, ll b, ll mod){
	a += b;
	if(a >= mod) a -= mod;
}

ll mult(ll a, ll b, ll mod){
	a %= mod;
	ll ans = 0;
	while(b){
		if(b & 1) madd(ans, a, mod);
		b >>= 1;
		madd(a, a, mod);
	}
	return ans;
}

ll f_exp(ll a, ll b, ll mod){
	a %= mod;
	ll ans = 1;
	while(b){
		if(b & 1) ans = mult(ans, a, mod);
		b >>= 1;
		a = mult(a, a, mod);
	}
	return ans;
}

bool is_prime(ll n){
	if(n <= 1) return 0;
	if(!(n & 1)) return n == 2;
	ll d = n - 1;
	ll s = 0;
	while(!(d & 1)) d >>= 1, s++;
	bool ret = 1;
	for(ll i = 3; i <= min(20LL, n - 1); i++){
		bool cur = false;
		if(f_exp(i, d, n) == 1) cur = true;
		else{
			for(ll j = 0; j <= s - 1; j++){
				if(f_exp(i, (1LL << j) * d, n) == n-1){
					cur = true;
					break;
				}
			}
		}
		ret *= cur;
	}
	return ret;
}

bool is_sqrt(ll x){
	ll sq = sqrt(x);
	for(ll w = sq - 2; w <= sq + 2; w++) if(w * w == x)
		return 1;
	return 0;
}

ll f(ll n){
	ll ans = 0;
	for(ll i = 2; i * i * i <= n; i++) if(n % i == 0){
		ans++;
		while(n % i == 0) n /= i;
	}
	if(n == 1) return ans;
	if(is_sqrt(n)) return ans+1;
	return is_prime(n) ? ans + 1 : ans + 2;
}

int main(){
	int t;

	ll n;

	scanf("%d", &t);

	fore(tc, 1, t+1){
		scanf("%lld", &n);

		ll k = f(n);
		
		printf("Caso #%d: %lld\n", tc, ((1LL << k) - 2)/2);
	}



    return 0;
}
