#include <bits/stdc++.h>

using namespace std;

int main(){
	int b;

	scanf("%d", &b);

	set<int> k;

	for(int i = 1; i <= sqrt(b); i++){
		if(b % i == 0){
			k.insert(i);
			k.insert(b/i);
		}
	}
	for(int i : k)
		printf(" %d", i);
	printf("\n");

	return 0;
}