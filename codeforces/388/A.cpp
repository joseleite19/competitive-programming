#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000

using namespace std;

int main(){
	int n;
	scanf("%d", &n);

	printf("%d\n", n/2);

	while(n > 3){
		printf("2 ");
		n -= 2;
	}

	printf("%d\n", n);

	return 0;
}