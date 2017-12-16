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

int n, l, r, ql, qr, v[N];

ll sum[N];

ll query(int i, int j){
	if(i) return sum[j] - sum[i-1];
	return sum[j];
}

int main(){

	scanf("%d %d %d %d %d", &n, &l, &r, &ql, &qr);

	fore(i, 1, n+1) scanf("%d", v+i);

	sum[0] = 0;

	for(int i = 1; i <= n+1; i++) sum[i] = sum[i-1] + v[i];

	ll ans = 1e18;

	for(int i = 0; i <= n+1; i++){
		int a = i, b = n - i;
		ll t = l*query(1, i) + r*query(i+1, n);
		if(a > b) t += (a - b - 1)*ql;
		else if(b > a) t += (b - a - 1) * qr;
		ans = min(ans, t);
	}

	printf("%lld\n", ans);


    return 0;
}
