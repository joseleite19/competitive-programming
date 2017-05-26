#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	int ans = 1000000;

	int x;
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		if(!x) continue;
		if(x <= k){
			ans = min(ans, abs(i - m));
		}
	}

	printf("%d\n", ans * 10);






	return 0;
}