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

const int N = 500005;

int n, v[N];

int main(){

	scanf("%d", &n);

	forn(i, n) scanf("%d", v+i);

	ll s = 0;
	forn(i, n) s += v[i];

	if(s % 3) return printf("0\n"), 0;

	s /= 3;

	map<ll, int> cnt;

	ll x = 0;
	for(int i = n-1; i >= 0; i--){
		x += v[i];
		cnt[x]++;
	}

	ll ans = 0;

	cnt[x]--;
	x -= v[0];

	for(int i = 0; i < n-1; i++){
		cnt[x]--;
		if(x == 2*s){
			ans += cnt[s];
		}
		x -= v[i+1];
	}


	printf("%lld\n", ans);


    return 0;
}
