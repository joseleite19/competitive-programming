#include <bits/stdc++.h>

int main(){
	int n, h, x, ans;

	scanf("%d %d", &n, &h);

	ans = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		ans += (x > h ? 2 : 1);
	}
	printf("%d\n", ans);

	return 0;
}