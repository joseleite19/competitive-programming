#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, k, v[200005];

int main(){

	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	int changes = 0;

	int used = 0;

	int i;
	for(i = 0; i < n; i++)
		if(v[i] < 0) break;

	if(i == n){
		printf("0\n");
		return 0;
	}

	if(k == 0){
		printf("-1\n");
		return 0;
	}

	changes = 1;
	// começa winter, vai ate onde dá
	// troca pra summer -> changes++, vai até onde dá
	// troca pra winter -> changes++
	// k--;

	while(i < n){
		int left = k - used;
		int j = min(i+left, n);
		// printf("%d %d %d %d %d\n", i, k, used, left, j);
		if(j == n) break;

		while(j > i && v[j] < 0) j--; // find pos for summer

		if(j == i){
			printf("-1\n");
			return 0;
		}

		// printf(".%d %d %d %d %d\n", i, k, used, left, j);
		while(j-1 > i && v[j-1] >= 0) j--; // find first pos for summer
		// printf(".%d %d %d %d %d\n", i, k, used, left, j);

		// ^ vai até onde dá
		used += j-i;
		changes++;

		// troquei pra summer

		if(j == n) break;
		while(j < n && v[j] >= 0) j++;
		if(j == n) break;

		changes++;
		i = j;
		if(used == k){
			printf("-1\n");
			return 0;
		}
		// printf("%d %d %d\n", j, changes, used);
	}
	printf("%d\n", changes);

	return 0;
}