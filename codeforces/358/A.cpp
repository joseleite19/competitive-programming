#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;

	long long count = 0;

	scanf("%d %d", &n, &m);

	long long mod1[5], mod2[5];

	memset(mod1, 0, sizeof mod1);
	memset(mod2, 0, sizeof mod2);

	for(int i = 1; i <= n; i++)
		mod1[ i % 5 ]++;
	for(int i = 1; i <= m; i++)
		mod2[ i % 5 ]++;

	printf("%lld\n", mod1[0] * mod2[0] + mod1[4] * mod2[1] + mod1[3] * mod2[2] + mod1[2] * mod2[3] + mod1[1] * mod2[4]);

	return 0;
}