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

int n;

ll k;

int a[N], b[N], c[N];

ll f(int mid){
	multiset<pair<int, int> > s;

	ll ans = 0, t = 0;
	forn(i, n){
		if(a[i] > mid){
			ans += 1LL*(a[i]-mid)*b[i];
			t += a[i] - mid;
		}
		else if(a[i] < mid){
			s.emplace(c[i], (mid-a[i]));
		}
	}
	
	int q, w;
	while(t > 0){
		if(s.empty()) return 1e18;
		tie(q, w) = *s.begin(); s.erase(s.begin());
		ll tmp = min(t, w*1LL);
		ans += tmp * q;
		t -= tmp;
	}

	return ans;
}

int main(){

	scanf("%d %lld", &n, &k);

	forn(i, n) scanf("%d %d %d", a+i, b+i, c+i);

	int L = 0, R = 1e7;

	while(L+1 < R){
		int mid = (L+R)/2;
		//printf("%d %lld\n", mid, f(mid));
		if(f(mid) > k) L = mid+1;
		else R = mid;
	}
	if(f(L) > k) L = R;

	printf("%d\n", L);


    return 0;
}
