#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	long long n, m, k, x, s, a[200005], b[200005], c[200005], d[200005];

	scanf("%lld %lld %lld", &n, &m, &k);
	scanf("%lld %lld", &x, &s);

	for(int i = 0; i < m; i++)
		scanf("%lld", a+i);
	for(int i = 0; i < m; i++)
		scanf("%lld", b+i);

	for(int i = 0; i < k; i++)
		scanf("%lld", c+i);
	for(int i = 0; i < k; i++)
		scanf("%lld", d+i);

	long long ans = n*x;

	for(int i = 0; i < m; i++){
		if(b[i] > s) continue;

		int tot = s - b[i];

		ans = min(ans, a[i]*n);

		int id = (upper_bound(d, d+k, tot) - d) - 1;

		if(id < 0) continue;

		ans = min(ans, a[i]*(n - c[id]));
	}

	for(int i = 0; i < k; i++){
		if(d[i] > s) break;
		ans = min(ans, x*(n - c[i]));
	}

	printf("%lld\n", ans);

	return 0;
}