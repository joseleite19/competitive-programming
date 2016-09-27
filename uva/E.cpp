#include <bits/stdc++.h>

using namespace std;

typedef long long Int;

#define MAX ( (Int) 1 << 63 )-1
#define gcc 10007
Int p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
Int Gcd(Int x, Int y) { return y ? Gcd(y, x % y) : x; }

inline Int produc_mod(Int a, Int b, Int mod) {
	Int sum = 0;
	a %= mod;
	while(b){
		if(b & 1) sum = (sum + a) % mod;
		a = (a + a) % mod;
		b /= 2;
	}
	return sum % mod;
}

inline Int power_mod(Int a, Int b, Int mod) {
	Int sum = 1;
	while(b) {
		if(b & 1) sum = produc_mod(sum, a, mod);
		a = produc_mod(a, a, mod);
		b /= 2;
	}
	return sum;
}

bool rabin_miller(Int n) {
	int i, j, k = 0; Int u, m, buf;
	if(n == 2) return true;
	if(n < 2 || !(n & 1)) return false;
	
	m = n-1;
	while(!(m & 1)) { k++; m /= 2; }
	for(i = 0; i < 9; i++) {
		if(p[i] >= n) return true;
		
		u = power_mod(p[i], m, n);
		if(u == 1) continue;
		
		for(j = 0; j < k; j++) {
			buf = produc_mod(u, u, n);
			if(buf == 1 && u != 1 && u != n-1)
				return false;
			u = buf;
		}
		if(u-1) return false;
	}
	return true;
}

double f(Int n){
	if(n <= 1) return 0;
	return n / log(n);
}

int main(){
	int t;
	Int a, b;

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		scanf("%lld %lld", &a, &b);

		int ans = 0;
		for(Int x = a; x <= b; x++)
			if(rabin_miller(x))
				ans++;


		printf("Teste %d: %.2lf\n", tc, ans - (f(b) - f(a-1)) + 1e-9);
	}


	return 0;
}