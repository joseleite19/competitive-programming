#include <bits/stdc++.h>

int main(){
	int t, n, ans, tmp;

	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		ans = 1;
		tmp = 9;
		while(n){
			if(n & 1) ans = (ans*tmp)%10;
			tmp = (tmp*tmp)%10;
			n >>= 1;
		}
		printf("%d\n", ans);
	}
}