#include <bits/stdc++.h>

using namespace std;

int main(){
	int k, a, b;

	int cnt = 0;

	scanf("%d %d %d", &k, &a, &b);

	cnt = (a/k) + (b/k);
	if(a % k){
		if(b < k) cnt = 0;
	}
	if(b % k){
		if(a < k) cnt = 0;
	}

	printf("%d\n", cnt ? cnt : -1);


	return 0;
}