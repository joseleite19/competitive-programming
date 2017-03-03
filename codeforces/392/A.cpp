#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int n, v[200];

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	int mx = 0;

	for(int i = 0; i < n; i++)
		mx = max(mx, v[i]);

	long long ans = 0;

	for(int i = 0; i < n; i++)
		ans += mx - v[i];

	printf("%lld\n", ans);

	return 0;
}