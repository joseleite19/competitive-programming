#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int main(){

	printf("100000\n");

	printf("10");
	for(int i = 1; i < 100000; i++)
		printf(" 10");
	printf("\n");

	for(int i = 1; i < 100000; i++)
		printf("%d %d\n", i, i+1);
	
	return 0;
}