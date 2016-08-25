#include <bits/stdc++.h>

using namespace std;

int n, v[100005];

long long k;

long long f(int x){
	long long ans = 0;
	for(int i = 0; i < n && x >= v[i]; i++)
		ans += upper_bound(v, v+i, x - v[i]) - v;
	return ans;
}

int main(){

	scanf("%d %lld", &n, &k);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	sort(v, v+n);

	int hi = v[n-1] + v[n-2], lo = v[0] + v[1], mid;

	while(hi > lo){
		mid = ((hi-lo) >> 1) + lo;
		if(f(mid) < k) lo = mid+1;
		else hi = mid;
	}

	printf("%d\n", lo);

	return 0;
}	