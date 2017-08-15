#include <bits/stdc++.h>

using namespace std;

int v[40], n, pass;

int main(){
	int t;

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", v+i);

		sort(v, v+n);

		long long sum = 0;

		long long ans = 0;
		for(int i = 0; i < n; i++){
			if(sum >= v[i]-1){
				sum += v[i];
			}
			else ans = sum+1;
		}
		if(!ans) ans = sum+1;
		printf("Conjunto #%d: %lld\n\n", tc, ans);
	}

	return 0;
}