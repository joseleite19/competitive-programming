#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, v[101];

	scanf("%d", &n);

	int max_dist = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", v + i);
		if(v[i] == 1 || v[i] == n) max_dist = max(max_dist, max(i, n - i - 1));
	}
	printf("%d\n", max_dist);

	return 0;
}