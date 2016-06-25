#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	return (b ? gcd(b, a%b) : a);
}

int main(){
	int a, b;

	scanf("%d %d", &a, &b);

	int n = gcd(a, b);
	int aux = n;
	long long complemento = 1;
	for(int i = 2; i < sqrt(n); i++){
		if(aux % i == 0){
			int count = 0;
			while(aux % i == 0){
				aux /= i;
				count++;
			}
			if(count & 1) complemento *= i;
		}
	}
	if(aux > 1) complemento *= aux;

	printf("%d\n", (int)sqrt(complemento*n));

	return 0;
}