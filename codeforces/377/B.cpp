#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int n, v[500], ans, k;

	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	if(n == 1){
		printf("0\n%d\n", v[0]);
		return 0;
	}

	int tmp = v[0] + v[1];
	int q;
	ans = 0;

	for(int i = 1; i < n; i++){
		tmp = v[i] + v[i-1];
		q = max(0, k - tmp);
		v[i] += q;
		ans += q;
	}

	printf("%d\n%d", ans, v[0]);

	for(int i = 1; i < n; i++)
		printf(" %d", v[i]);
	printf("\n");


	return 0;
}