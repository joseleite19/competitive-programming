#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;

	scanf("%d", &t);

	while(t--){

		int n;

		scanf("%d", &n);

		int v1[n];
		int v2[n];

		for(int i = 0; i < n; i++){
			scanf("%d", &v1[i]);
		}

		for(int i = 0; i < n; i++){
			scanf("%d", &v2[i]);
		}

		sort(v1+1,v1+n);
		sort(v2,v2+n); reverse(v2, v2+n);

		map<long long, int> m;
		long long big = -1;
		for(int i = 0; i < n; i++){
			m[1LL*v1[i]*v2[i]]++;
			big = max(big, 1LL*v1[i]*v2[i]);
		}

		long long prim = 1LL*v1[0]*v2[0];
		if(big == prim && m[prim] == 1) printf("YES\n");
		else printf("NO\n");


	}

	return 0;
}