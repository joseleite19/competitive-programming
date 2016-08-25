#include <bits/stdc++.h>

using namespace std;

long long f(int n){
	return (long long)n*(n+1)/2;
}

int main(){
	int n, k;
	int v[100005];

	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i++)
		scanf("%d", v + i);

	int tmp = 0;
	while(f(tmp) <= k){
		tmp++;
	}

	tmp--;

	printf("%d %lld\n", k, f(tmp));

	return 0;
}