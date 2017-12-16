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
		x = max(0, x - ans);
	}
	return ans;
}

int main(){

	printf("%lld\n", f(8, 1));

	


	return 0;
}