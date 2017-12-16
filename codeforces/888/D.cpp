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

int main(){

	int n, k;

	scanf("%d %d", &n, &k);

	ll ans = 1;

	if(k == 1) return printf("%lld\n", ans), 0;

	ans += 1LL * n * (n-1) / 2;

	if(k == 2) return printf("%lld\n", ans), 0;
	ans += 1LL * n * (n-1) * (n-2) / 3;
	if(k == 3) return printf("%lld\n",  ans), 0;

	ans += 9LL * n * (n - 1) * (n - 2) * (n - 3) / 24;

	printf("%lld\n", ans);
    return 0;
}
