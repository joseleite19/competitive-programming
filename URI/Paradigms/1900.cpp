#include <bits/stdc++.h>

#define MAXN 100005
int toright[MAXN], toleft[MAXN], v[MAXN], n;

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v + i);

	toright[0] = v[0];
	for(int i = 1; i < n; i++)
		toright[i] = v[i] + toright[i-1];

	std::sort(toright, toright+n);

	long long ans = 0;
	for(int i = 0; i < n; i++){
		int tmp = std::upper_bound(toright+i+1, toright+n, toright[i]) - toright;
		ans += tmp - i - 1;
		if(toright[i] == 0) ans++;
	}
	printf("%lld\n", ans);

}