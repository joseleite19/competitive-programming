#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, v[1111];

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	printf("%s\n", prev_permutation(v, v+n) ? "no" : "yes");

	return 0;
}