#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;

	scanf("%d", &n);

	int minimum;
	int maximum;

	minimum = 1000000000;
	maximum = -1;
	for(int i = 0; i < 7; i++){
		int aux = 0;
		for(int j = 0; j < n; j++){
			if((j + i) % 7 < 2)
				aux++;
		}
		minimum = min(minimum, aux);
		maximum = max(maximum, aux);
	}
	printf("%d %d\n", minimum, maximum);

	return 0;
}