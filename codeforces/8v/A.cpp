#include <bits/stdc++.h>

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 1; i <= 1000; i++){
		int k = n*i + 1;
		for(int j = 2; j*j <= k; j++){
			if(k % j == 0){
				printf("%d\n", i);
				return 0;
			}
		}
	}
	
	return 0;
}