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
#define ford(i, a, b) for(int i = int(a); i >= int(b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 1e3 + 5;
const ll MAX_VAL = (ll) 1e18;
vector<int> primes;
bool prime[MAX];

void sieve() {
	memset(prime, true, sizeof prime);
	primes.push_back(2);
	for(int i = 3; i < MAX; i += 2) {
		if(prime[i]) {
			primes.push_back(i);
			for(int j = i * i; j < MAX; j += 2 * i) {
				prime[j] = false;
			}
		}
	}
}

bool overflow(ll a, ll b) {
	return a >= MAX_VAL / b;
}

ll my_pow(ll x, ll exp) {
	ll ans = 1;
	fori(i, 0, exp) {
		if(overflow(ans, x)) {
			return MAX_VAL;
		}
		ans *= x;
	}
	return ans;
}

double get_val(const vector<ii> &guys) {
	double lg = 0.0;
	fori(i, 0, guys.size()) {
		lg += log(guys[i].first) * (guys[i].second - 1);
	}
	return lg;
}

int main(){
	int kase = 1;
	sieve();
	int t;
	scanf("%d", &t);
	while(t--) {
		vector<int> factors;
		int n;
		scanf("%d", &n);
		for(int i = 0; i < (int) primes.size() && primes[i] * primes[i] <= n; i++) {
			while(n % primes[i] == 0) {
				factors.push_back(primes[i]);
				n /= primes[i];
			}
		}
		if(n != 1) {
			factors.push_back(n);
		}
		sort(factors.begin(), factors.end(), greater<int>());
		vector<ii> guys;
		fori(i, 0, factors.size()) {
			guys.emplace_back(primes[i], factors[i]);
		}
		while(1) {
			double lg = get_val(guys);
			double best = lg;
			vector<ii> the_best;
			fori(j, 0, guys.size() - 1) {
				auto tmp = guys;
				tmp[j].second *= guys.back().second;
				tmp.pop_back();
				double cur = get_val(tmp);
				if(best > cur) {
					best = cur;
					the_best = tmp;
				}
			}
			if(the_best.empty()) {
				break;
			}
			guys = the_best;
		}
		ll ans = 1;
		fori(i, 0, guys.size()) {
			ll cur = my_pow(guys[i].first, guys[i].second - 1);
			if(overflow(cur, ans)) {
				ans = MAX_VAL;
				break;
			}
			ans *= cur;
		}
		if(ans < MAX_VAL) {
			printf("Caso #%d: %lld\n", kase++, ans);
		}
		else {
			printf("Caso #%d: infinito\n", kase++);
		}
	}


    return 0;
}
