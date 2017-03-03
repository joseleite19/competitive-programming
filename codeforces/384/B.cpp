#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int acha(long long final, long long k){
	if(final/2 + 1 == k)
		return __builtin_popcountll(final);

	long long newf = final/2;
	if(k > final/2) k = k - (final - newf);

	return acha(newf, k);
}

int main(){
	int n;
	long long k;

	scanf("%d %lld", &n, &k);

	long long final = (1LL << n) - 1;

	printf("%d\n", acha(final, k));

	return 0;
}