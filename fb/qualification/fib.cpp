#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

double tt[21][22][404];

int main(){
	long long fib[100];

	fib[0] = fib[1] = 1;

	for(int i = 2; i < 50; ++i)
		fib[i] = fib[i-1] + fib[i-2];

	for(int i = 0; i < 50; i++){
		printf("%d %lld\n", i, fib[i]);
	}
	
	return 0;
}