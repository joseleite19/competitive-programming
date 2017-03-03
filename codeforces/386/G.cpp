#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, t, k, v[200005], p[200005];

int main(){

	scanf("%d %d %d", &n, &t, &k);

	for(int i = 0; i < t; i++)
		scanf("%d", v+i);

	int leaf = v[t-1];

	for(int i = 0; i < t-1; i++)
		if(v[i] > v[i+1])
			leaf += v[i] - v[i+1];

	if(leaf > k || k > n-t){
		printf("-1\n");
		return 0;
	}

	int ptr = n;

	for(int i = t-1; i > 0; i--){
		int limit = min(v[i], v[i-1]);
		int last = ptr - v[i];
	
		if(k - leaf > 0){
			int left = k - leaf;
			
			if(left > limit-1){
				leaf += limit-1;
				limit = 1;
			}
			else{
				leaf += left;
				limit -= left;
			}
		}

		int j;
		for(j = 0; j < limit; j++)
			p[ptr] = ptr - v[i], ptr--;

		for(; j < v[i]; j++)
			p[ptr--] = last;
	}

	for(int j = 0; j < v[0]; j++)
		p[ptr--] = 1;

	printf("%d\n", n);

	for(int i = 2; i <= n; i++)
		printf("%d %d\n", p[i], i);

	return 0;
}