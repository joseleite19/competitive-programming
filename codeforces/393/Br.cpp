#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

long long bhaskara(double a, double b, double c){
	double x = ((-b + sqrt(b*b - 4*a*c)) / 2 / a);
	double y = ((-b - sqrt(b*b - 4*a*c)) / 2 / a);
	x = max(x, y);
	return (long long) (x);
}

int main () {
	
	long long n, m, k;
	long long l, r, ll, rr;
	long long resp = 0;
	
	bool al = false, bl = false;
	
	scanf("%lld %lld %lld", &n, &m, &k);
	
	l = k - 1;
	r = n - k;
	
	ll = rr = 0;
	
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
	
	if(ll > l) ll = l;
	if(rr > r) rr = r;
	
	if (al && bl) {
		resp += m / (l + r + 1);
	} else if (al || bl) {

		long long f = max(r - rr, l - ll);

		long long c = bhaskara(0.5, (ll + rr + 1) - 0.5, - m);

		if(c > f) c = f;

		m -= (c * (ll + rr + 1) + c*(c-1)/2);
		resp += c;

		rr = r, ll = l;
		
		resp += m / (ll + rr + 1);
	}
	
	printf("%lld\n", resp);
	
	return 0;
	
}