#include <bits/stdc++.h>

int main(){
	int T;
	long long n;

	scanf("%d", &T);

	for(int t = 1; t <= T; t++){
		scanf("%lld", &n);
		long long complemento = 1, aux = n;
		for(int i = 2; i <= sqrt(n); i++){
			if(aux % i == 0){
				int j = 0;
				while(aux % i == 0){
					aux /= i;
					j++;
				}
				if(j & 1) complemento *= i;
			}
		}
		if(aux > 1) complemento *= aux;

		printf("Caso #%d: %lld\n", t, n * complemento);
	}

	return 0;
}