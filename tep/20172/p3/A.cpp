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

int main(){
	int kase = 1;
	int t;
	scanf("%d", &t);
	while(t--) {
		ll g, d;
		ll r, tmp;
		scanf("%lld %lld %lld.%lld", &g, &d, &r, &tmp);
		r = 100 * r + tmp;
		double ans = 1e3 * r /((100 - d) * g);
		printf("Caso %d: %.8lf\n", kase++, ans);
	}


    return 0;
}
