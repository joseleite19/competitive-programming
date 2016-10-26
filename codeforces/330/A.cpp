#include <bits/stdc++.h>

using namespace std;

long long v[200005];

int main(){
	int n;

	scanf("%d\n", &n);
	for(int i = 0; i < n; i++)
		scanf("%lld", v+i);

	sort(v, v+n);

	int x = (n-1)/2 + 1;
	long long ans = 2e18;
	for(int i = x; i < n; i++)
		ans = min(ans, v[i] - v[i-x]);

	printf("%lld\n", ans);

	return 0;
}