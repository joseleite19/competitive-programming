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

const int N = 200005;

int n, v[N];

ll sum[N];

ll query(int a, int b){
	return sum[b] - (a ? sum[a-1] : 0);
}

int main(){

	scanf("%d", &n);

	ll all = 0;
	forn(i, n) scanf("%d", v+i), all += v[i];

	map<ll, ll> s, cnt;

	forn(i, n) cnt[ v[i] ]++, s[ v[i] ] += v[i];

	unsigned long long a = 0, b = 0, tmp;
	forn(i, n){
		ll t = 0;
		t = all - s[ v[i]-1 ] - s[ v[i] ] - s[ v[i]+1 ];
		ll x = n-i - cnt[ v[i]-1 ] - cnt[ v[i] ] - cnt[ v[i]+1 ];

		t -= x * v[i];

		if(t >= 0) a += t;
		else b -= t;

		tmp = min(a, b);
		a -= tmp, b -= tmp;

		cnt[ v[i] ]--, s[ v[i] ] -= v[i];
		all -= v[i];
	}

	if(b > 0) printf("-%llu\n", b);
	else printf("%llu\n", a);

    return 0;
}
