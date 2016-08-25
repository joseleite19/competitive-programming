#include <bits/stdc++.h>

using namespace std;

int a;

long long calc(int *v, int n){
	if((v[0] - a > 0) == (v[n-1] - a > 0)) return max(abs(v[0]-a), abs(v[n-1]-a));
	long long q = min(abs(v[0]-a), abs(v[n-1]-a));
	return q + abs(v[n-1] - v[0]);
}

int main(){
	int n, v[100005];

	scanf("%d %d", &n, &a);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	sort(v, v+n);

	if(n == 1){
		printf("0\n");
		return 0;
	}
	else if(n == 2){
		printf("%d\n", min(abs(v[0]-a), abs(v[1]-a)));
		return 0;
	}

	printf("%lld\n", min(calc(v,n-1), calc(v+1, n-1)));
	return 0;
}

// -2 0 0 1 2