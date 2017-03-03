#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

long long ft[1000006];
int n, k;
void add(int x, long long v){
	for(; x <= n; x += x&-x)
		ft[x] += v;
}

long long sum(int x){
	long long ans = 0;
	for(; x; x -= x&-x)
		ans += ft[x];
	return ans;
}

int main(){

	scanf("%d %d", &n, &k);

	int v = 1;

	long long ans = 1;
	// add(1, 1);
	k = min(k, n-k);

	for(int i = 0; i < n; i++){
		int to = v + k;
		if(to > n){
			to -= n;
			// printf("asd\n");
			int x = sum(n) - sum(v) + sum(to-1);
			// printf("\n%d %d %d: %d\n", sum(n), sum(v), sum(to), v);
			add(v, 1);
			add(to, 1);
			ans += x+1;
		}
		else{
			int x = abs(sum(to-1) - sum(v));
			// printf("i = %d; %d %d\n", i, sum(to-1), sum(v+1));
			add(v, 1);
			add(to, 1);
			ans += x+1;
		}
		v = to;
		printf("%lld ", ans);
	}
	printf("\n");

	return 0;
}