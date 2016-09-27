#include <bits/stdc++.h>

int exp(long long b, int e){
	long long ans = 1;

	while(e){
		if(e & 1) ans = (ans * b) % 7340033;
		b = (b*b) % 7340033;
		e >>= 1;
	}
	return ans % 7340033;
}

int main(){
	printf("%d\n", !!5);
	printf("%d\n", exp(5, 7340033-2));
}