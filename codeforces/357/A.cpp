#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, before[101], after[101];

	scanf("%d", &n);

	int good = false;
	for(int i = 0; i < n; i++){
		scanf(" %*s %d %d", before + i, after + i);
		if(before[i] >= 2400 && after[i] > before[i])
			good = true;
	}

	printf("%s\n", good ? "YES" : "NO");

	return 0;
}