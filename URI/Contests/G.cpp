#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	return (b ? gcd(b, a % b) : a);
}

int lcm(int a, int b){
	return (a / gcd(a, b)) * b;
}

int main(){
	int n, b[101], times[101];

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", b + i);

	int mmc = 1;
	for(int i = 0; i < n; i++){
		int count = 1, ptr = b[i]-1;
		while(ptr != i){
			ptr = b[ptr]-1;
			count++;
		}
		mmc = lcm(mmc, count);
	}

	printf("%d\n", mmc);

	return 0;
}