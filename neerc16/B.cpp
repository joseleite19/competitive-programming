#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}


int main(){
	long long n, b, a;

	scanf("%lld %lld %lld", &n, &b, &a);

	long long lo = n - a, hi = b;

	if(hi <= lo+1) return printf("OK\n"), 0;

	long long d = gcd(a, b);

	long long x = n - a + 1;

	if(x % d == 0) return printf("DEADLOCK\n"), 0;
	
	long long D = x % d + (hi - lo - 1) - 1;

	if(D >= d) return printf("DEADLOCK\n"), 0;

	printf("OK\n");




	return 0;
}