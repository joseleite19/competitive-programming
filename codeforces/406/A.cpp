#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int a, b, c, d;
int vet[2000000];
int main(){

	scanf("%d %d %d %d", &a, &b, &c, &d);

	for(int i = b; i <= 20000; i += a)
		vet[i] = 1;

	int ans = -1;
	for(int i = d; i <= 20000; i += c){
		if(vet[i]){
			ans = i;
			break;
		}
	}

	printf("%d\n", ans);
	

	return 0;
}