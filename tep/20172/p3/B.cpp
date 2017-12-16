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
typedef pair<ll, ll> ii;

const int N = 100005;

char s[N];

ll lcm(ll a, ll b){
	return a / __gcd(a, b) * b;
}

int main(){

	int r;

	scanf("%d", &r);

	int n;

	map<string, pair<ll, ii> > m;
	while(r--){
		scanf("%d", &n);

		fore(i, 0, n){
			ll a, b, c;
			scanf(" %lld(%lld/%lld) %[^\n]", &a, &b, &c, s);
			if(!m.count(s)) m[s].ss.ss = 1;
			m[s].ff += a;
			m[s].ss.ff = m[s].ss.ff * c + b * m[s].ss.ss;
			m[s].ss.ss = m[s].ss.ss * c;

			m[s].ff += m[s].ss.ff / m[s].ss.ss;
			m[s].ss.ff %= m[s].ss.ss;
			
			ll g = __gcd(m[s].ss.ff, m[s].ss.ss);
			m[s].ss.ff /= g, m[s].ss.ss /= g;
		}
	}
	
	for(const auto &x : m){
		printf("%lld(%lld/%lld) %s\n", x.ss.ff, x.ss.ss.ff, x.ss.ss.ss, x.ff.c_str());
	}

	return 0;
}
