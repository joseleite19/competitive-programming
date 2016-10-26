#include <bits/stdc++.h>

long long mdc(long long a, long long b){
	return b ? mdc(b, a % b) : a;
}

long long mmc(long long a, long long b){
	return a/mdc(a, b) * b;
}

int main(){
	long long ans = 1;

	for(int i = 1; i <= 40; i++){
		ans = mmc(ans, i);
		printf("%d %lld\n", i, ans);
	}


	return 0;
}