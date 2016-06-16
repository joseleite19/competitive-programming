#include <bits/stdc++.h>

using namespace std;

#define MOD (1000000007)
#define MAXN (10000007)

int exp(int base, int exp){
	int result = 1;
	while(exp){
		if(exp & 1) result = ((long long)result * base) % MOD;
		base = ((long long)base * base) % MOD;
		exp >>= 1;
	}
	return result;
}


int main(){
	int divisores[MAXN+4], numbers[MAXN+4];
	int a, b, n, i, j, count;

	scanf("%d %d %d", &a, &b, &n);


	for(int i = 1; i <= b; i++)
		divisores[i] = 1, numbers[i] = i;

	divisores[2] = 2;
	for(j = 4; j <= b; j += 2){
		for(count = 1; numbers[j] & 1 == 0; numbers[j] /= 2, count++);
		divisores[j] *= count;
	}

	for(i = 3; i*i <= b; i += 2){
		if(divisores[i] == 1){
			divisores[i]++;
			for(j = i+i; j <= b; j += i){
				for(count = 1; numbers[j] % i == 0; numbers[j] /= i, count++);
				divisores[j] *= count;
			}
		}
	}

	int qnt_primes = 0;
	for(int i = a; i <= b; i++){
		if(i*i <= b){
			if(divisores[i] == n) qnt_primes++;
		}
		else if(numbers[i] > 1 && 2*divisores[i] == n) qnt_primes++;
	}

	printf("%d\n", exp(qnt_primes, b - a + 1 - qnt_primes));

	return 0;
}