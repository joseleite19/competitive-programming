#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int f(int n){
	int cnt = 0;
	if(n == 1) return 1;

	for(int i = 1; i < n; i++){
		if(gcd(i, n - i) == 1){
			printf("%d %d\n", i, n-i);
			cnt++;
		}
	}

	return cnt;
}

int main(){

	for(int i = 1; i < 20; i++){
		int ret = f(i);
		printf("%d: %d\n\n", i, ret);
	}


	return 0;
}