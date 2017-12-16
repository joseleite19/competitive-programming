#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

long long n, m;

long long f(long long n, long long m){
	long long ans = 0;
	long long x = n;
	while(x){
		x = min(n, x + m);
		ans++;
		x = max(0LL, x - ans);
	}
	return ans;
}

long long func(long long x){
	long long tmp = max(0LL, (long long)sqrt(2*x) - 5);

	for(long long i = 1; i <= 1000; i++)
		if((tmp+i)*(tmp+i+1) >= 2*x){
			return tmp+i;
		}
}

long long f2(long long n, long long m){
	if(n <= m+2) return n;

	long long x = n - m;
	return func(x) + m;
	// return ceil((sqrt(8*x+1)-1) / 2) + m;
}

int main(){

	scanf("%lld %lld", &n, &m);

	printf("%lld\n", f2(n, m));

	// for(long long i = 1; i <= 1000; i++)
	// 	for(long long j = 1; j <= 1000; j++)
	// 		if(f(i, j) != f2(i, j))
	// 			printf("%lld %lld\n", i, j);
	// 		// printf("%lld %lld\n", i, f(i, 2));

	


	return 0;
}