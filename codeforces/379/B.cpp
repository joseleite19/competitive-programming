#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	long long k2, k3, k5, k6;

	scanf("%lld %lld %lld %lld", &k2, &k3, &k5, &k6);

	long long tmp = min(min(k2, k5), k6);

	k2 -= tmp;

	long long tmp2 = min(k2, k3);

	printf("%lld\n", 256*tmp + 32*tmp2);


	return 0;
}