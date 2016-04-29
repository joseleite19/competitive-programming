#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	if(n % 3 == 0) printf("%d\n", (n / 3) * 2);
	else printf("%d\n", (n / 3) * 2 + 1);
}