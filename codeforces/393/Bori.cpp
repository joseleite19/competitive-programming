#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main () {
	
	long long n, m, k;
	long long l, r, ll, rr;
	long long resp = 0;
	
	bool al= false, bl = false;
	
	scanf("%lld %lld %lld", &n, &m, &k);
	
	l = k - 1;
	r = n - k;
	
	ll = rr = 0;
	
	if (ll > l)
		ll = l;
	if (rr > r)
		rr = r;
	
	resp++;
	m -= n;
	
	long long a = sqrt(m);
	
	resp += a;
	m -= a * a;
	
	a--;
	
	if (l <= a) {
		int diff = a - l;
		
		m += diff * (diff + 1) / 2;
		ll = l;
		al = true;
	} else {
		ll = a + 1;
	}
	if (r <= a) {
		int diff = a - r;
		
		m += diff * (diff + 1) / 2;
		rr = r;
		bl = true;
	} else {
		rr = a + 1;
	}
	if (ll > l)
		ll = l;
	if (rr > r)
		rr = r;
	
	if (al && bl) {
		resp += m / (l + r + 1);
	} else if (!al && ! bl) {
		
	} else {

		printf("%lld %lld %lld %lld, %lld\n", r - rr, l - ll, m, resp, ll + rr + 1);
		
		while (m >= ll + rr + 1) {
			if(l == ll && r == rr) printf(";;%lld\n", m);
			m -= ll + rr + 1;
			resp++;
			ll++;
			rr++;
			if (ll > l)
				ll = l;
			if (rr > r)
				rr = r;
		}
		printf("%lld %lld %lld %lld\n", r - rr, l - ll, m, resp);
	}
	
	printf("%lld\n", resp);
	
	return 0;
	
}