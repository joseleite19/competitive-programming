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
const ll oo = 1e18;

ll v[N];
int n, d;

ll s[N];
int main(){

	scanf("%d %d", &n, &d);

	forn(i, n) scanf("%lld", v+i);

	int ans = 0;

	partial_sum(v, v+n, s);

	for(int i = n-2; i >= 0; i--)
		s[i] = max(s[i], s[i+1]);

	ll saldo = 0, delta = 0;
	for(int i = 0; i < n; i++){
		saldo += v[i];
		if(saldo > d) return printf("-1\n"), 0;
		if(v[i] == 0 && saldo < 0){
			ll x = d - (delta + s[i]);
			if(saldo + x < 0) return printf("-1\n"), 0;
			ans++;
			saldo += x;
			delta += x;
		}
	}
	printf("%d\n", ans);

    return 0;
}
