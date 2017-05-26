#include <bits/stdc++.h>

using namespace std;

int main(){
	long long fat[40];
	fat[0] = 1;
	for(int i = 1; i < 34; i++)
		fat[i] = i*fat[i-1];

	int n;

	scanf("%d", &n);

	printf("%d\n", n*n*n);

	return 0;
}