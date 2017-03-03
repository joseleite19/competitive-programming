#include <bits/stdc++.h>

int f(int n){
	int b = 8;
	int ans = 1;

	while(n){
		if(n & 1) ans = (ans*b)%10;
		b = (b*b)%10;
		n >>= 1;
	}

	return ans;
}

int main(){
	int n;

	scanf("%d", &n);

	printf("%d\n", f(n));
}