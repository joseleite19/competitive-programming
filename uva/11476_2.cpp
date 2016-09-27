#include <bits/stdc++.h>

using namespace std;

typedef long long Int;

// bool rabin_miller(Int n) {
// 	int i, j, k = 0; Int u, m, buf;
// 	if(n == 2) return true;
// 	if(n < 2 || !(n & 1)) return false;
// 	m = n-1;
// 	while(!(m & 1)) { k++; m /= 2; }
// 	for(i = 0; i < 9; i++) {
// 	if(p[i] >= n) return true;
// 	u = power_mod(p[i], m, n);
// 	if(u == 1) continue;
// 	for(j = 0; j < k; j++) {
// 	buf = produc_mod(u, u, n);
// 	if(buf == 1 && u != 1 && u != n-1) return false;
// 	u = buf;
// 	}
// 	if(u-1) return false;
// 	}
// 	return true;
// }

const int MAXN = 100000001, SIZE = MAXN/16+1;
const int MAX_PRIMES = 6850000; // 1.26 * MAXN / log(MAXN);
char mark[SIZE]; // ( mark[n>>4]&(1<<((n>>1)&7)) ) == 0 se 2*n+1 eh primo
char _is_prime[MAXN];
int primes[MAX_PRIMES], cnt_primes;
void sieve( int N ) {
	int i, j;
	for(i = 3; i*i <= N; i += 2 ) if ( ( mark[i>>4] & (1<<((i>>1)&7)) ) == 0 )
		for(j = i*i; j <= N; j += i<<1 ) mark[j>>4] |= ( 1<<((j>>1)&7) );
	cnt_primes = 0;
	primes[cnt_primes++] = 2;
	for(i = 3; i <= N; i += 2 ) if ( (mark[i>>4]&(1<<((i>>1)&7))) == 0 )
		primes[cnt_primes++] = i;
	for(i = 0; i < cnt_primes; i++) _is_prime[primes[i]] = 1;
}

bool is_prime(long long n){
	int limit = sqrt(n) + 1;
	for(int i = 0; i < limit; i++)
		if(n % primes[i] == 0)
			return false;
	return true;
}

#define MAX ( (Int) 1 << 63 )-1
#define gcc 10007
Int p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
Int Gcd(Int x, Int y) { return y ? Gcd(y, x % y) : x; }

inline Int produc_mod(Int a, Int b, Int mod) {
	Int sum = 0;
	while(b){
		if(b & 1) sum = (sum + a) % mod;
		a = (a + a) % mod;
		b /= 2;
	}
	return sum;
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

Int pollard_rho(Int n) {
	while(1) {
		int i = 1;
		Int x = rand() % (n-1) + 1, y = x, k = 2, d;
		do {
			i++;
			d = Gcd(n + y - x, n);
			if(d > 1 && d < n) return d;
			if(i == k) y = x, k *= 2;
			x = ( produc_mod(x, x, n) + n - gcc ) % n;
		} while(y != x);
	}
}

Int prime[1000000];
int top;
void prime_divisor(Int key) {
	if(rabin_miller(key)) prime[top++] = key;
	else{
		Int buf = pollard_rho(key);
		if(rabin_miller(buf)) prime[top++] = buf;
		else prime_divisor(buf);
		if(rabin_miller(key / buf)) prime[top++] = key / buf;
		else prime_divisor(key / buf);
	}
}


int main(){
	int t;
	long long n;
	// sieve(MAXN-1);

	scanf("%d", &t);

	while(t--){
		top = 0;
		scanf("%lld", &n);
		printf("%lld =", n);
		// if(is_prime(n)){
		// 	printf(" %lld\n", n);
		// 	continue;
		// }

		map<long long, int> ww;



		prime_divisor(n);
		for(int i = 0; i < top; i++)
			ww[ prime[i] ]++;
		bool first = true;
		for(map<long long, int>::iterator it = ww.begin(); it != ww.end(); it++){
			if(!first) printf(" *");
			first = false;
			if(it->second == 1) printf(" %lld", it->first);
			else printf(" %lld^%d", it->first, it->second);
		}
		printf("\n");
	}


	return 0;
}