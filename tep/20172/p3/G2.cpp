#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define debug(x) //cout << #x << " = " << x << endl
#define ford(i, a, b) for(int i = int(a); i >= int(b); i--)
#define N 1000006

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 1e3 + 5;
const ll MAX_VAL = (ll) 1e18;
vector<int> primes;
bool prime[MAX];
vector<int> divs;
ll dp[N][21];
int mark[N][21];
int pass;
vector<long long> po[21];


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

ll f(int n, int id){
	debug(n);
	debug(id);
	if(n == 1) return 1;
	if(id > 20) return MAX_VAL;

	if(mark[n][id] == pass) return dp[n][id];
	mark[n][id] = pass;

	ll ans = MAX_VAL;
	for(int i : divs){
		debug(i);
		debug(po[id].size());
		if(i > n) break;
		if(po[id].size() < i) break;
		if(n % i) continue;
		if(overflow(f(n / i, id+1),po[id][i-1])) continue; 
		ll tmp = f(n / i, id+1) * po[id][i-1];
		ans = min(ans, tmp);  
	}
	
	return dp[n][id] = ans;
}


int main(){
	int kase = 1;
	int t;
	sieve();
	for(int i = 0; i < 21; i++){
		long long x = 1;
		while(x <= MAX_VAL && x > 0){
			po[i].pb(x);
			if(overflow(x,primes[i])) break;
			x *= primes[i];
		}
	}

	scanf("%d", &t);
	while(t--) {
		pass++;
		int n;
		scanf("%d", &n);
		int x = sqrt(n);
		divs.pb(n);
		for(int i = 2; i <= x; i++){
			if(n % i == 0){
				divs.pb(i);
				if(n/i != i)
					divs.pb(n/i);
			}
		}
		sort(divs.begin(),divs.end());
		ll ans = f(n,0);
		if(ans < MAX_VAL){	
			printf("Caso #%d: %lld\n", kase++, ans);
		}
		else {
			printf("Caso #%d: infinito\n", kase++);
		}
		divs.clear();
	}


    return 0;
}
