#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b){
	return (b ? gcd(b, a % b) : a);
}

int main(){
	int n, t1, t2, t;
	long long num, dem;

	while(scanf("%d %d %d", &t1, &t2, &n) == 3){
		t = (t2-t1) * 60;
		num = (long long)n * (2*t - n);
		dem = (long long)t*t;

		long long factor = gcd(num, dem);
		printf("%lld/%lld\n", num / factor, dem / factor);
	}

	return 0;
}