#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);
		printf("Conjunto: %d %d %d\n", a, b, c);

		while(c--){
			if(a > b) a /= 2;
			else b /= 2;
		}

		if(a < b) swap(a, b);
		printf("%d %d\n\n", a, b);
	}

	return 0;
}