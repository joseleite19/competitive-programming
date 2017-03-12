#include <bits/stdc++.h>

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int main(){
	// file();
	int n, k;
	scanf(" %d %d", &n, &k);
	
	// n = ((2*n + 2*k-2) / k);
	// printf("%d\n", (int)ceil((n/k) * 2));
	int ans = (2*n + k - 1) / k;

	if(n < k) ans = 2;

	printf("%d\n", ans);
	return 0;
}