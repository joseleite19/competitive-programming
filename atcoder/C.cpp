#include <bits/stdc++.h>

using namespace std;

int digits(long long a){
	int cnt = 0;
	while(a) cnt++, a /= 10;
	return cnt;
}

int f(long long a, long long b){
	return max(digits(a), digits(b));
}


int main(){
	long long n;

	scanf("%lld", &n);

	int ans = 10000000;
	for(long long i = 1; i*i <= n; i++){
		if(n % i == 0){
			ans = min(ans, f(i, n/i));
		}
	}

	printf("%d\n", ans);

	return 0;
}