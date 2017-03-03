#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

long long f2(long long n){
	return (n + 1) * n / 2;
}

long long f3(long long mid, long long tam){
	if(mid < tam)
		return f2(mid) + (tam - mid);
	return f2(mid) - f2(mid - tam);
}

long long n, m, k;

long long f(long long mid){
	return f3(mid, k) + f3(mid, n-k+1) - mid;
}

int main(){

	scanf("%lld %lld %lld", &n, &m, &k);

	long long hi = m, lo = 1;

	while(lo + 1 < hi){
		int mid = (lo + hi) / 2;

		if(f(mid) <= m) lo = mid;
		else hi = mid-1;
	}

	if(f(hi) > m) hi--;

	long long ans = hi;

	printf("%lld\n", ans);

	return 0;
}