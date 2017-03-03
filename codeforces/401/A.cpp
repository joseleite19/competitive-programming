#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int main(){

	long long n, x;

	scanf("%lld %lld", &n, &x);

	long long tmp = n / 2;
	if(n & 1){
		if(x <= 1){
			x = (x + 1) % 2;
		}
	}

	x = (x + tmp) % 3;

	printf("%lld\n", x);


	return 0;
}