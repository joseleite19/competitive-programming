#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){

	int t;
	int mat[502][502], v[502];

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		int n;

		scanf("%d", &n);
		memset(v, 0, sizeof v);

		int x;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				scanf("%d", &x);
				v[abs(i-j)] |= x;
			}
		}

		int i = 0;
		for(; i < n+1; i++)
			if(!v[i+1])
				break;
		printf("%d\n", i);

	}

	return 0;
}