#include <bits/stdc++.h>


int main(){
	int n, b, d, x;

	int cur = 0;
	int ans = 0;

	scanf("%d %d %d", &n, &b, &d);

	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		if(x > b) continue;
		cur += x;
		if(cur > d){
			cur = 0;
			ans++;
		}
	}
	printf("%d\n", ans);
}