#include <bits/stdc++.h>

int main(){
	int n, v[100005];

	scanf("%d", &n);

	long long sum = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", v+i);
		sum += v[i]-1;
		printf("%d\n", (sum & 1) ? 1 : 2);
	}	

	return 0;
}