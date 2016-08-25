#include <bits/stdc++.h>

#define ff first
#define ss second

#define oo 1000000000

using namespace std;

int main(){
	int n, v[100005], q, m;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	sort(v, v+n);

	scanf("%d", &q);

	while(q--){
		scanf("%d", &m);

		printf("%d\n", upper_bound(v, v+n, m) - v);
	}

	return 0;
}