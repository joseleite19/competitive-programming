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

int n, m, v[N];

int main(){

	scanf("%d %d", &n, &m);

	forn(i, m) scanf("%d", v+i), v[i]--;
	
	ll ans = 0;
	int p = 0;

	forn(i, m){
		int t = v[i] - p;
		if(t < 0) t += n;
		ans += t;
		p = v[i];
	}

	printf("%lld\n", ans);



    return 0;
}
