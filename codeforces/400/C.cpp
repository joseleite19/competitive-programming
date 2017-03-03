#include <bits/stdc++.h>

using namespace std;

// xxxxxxxxxxxxxxxxxxx
//        ^       ^
//        b       a
// a - b = x
// a - x = b

int n;
long long sum[100005], v[100005], k;

long long target[100];

map<long long, long long> cnt;

int main(){

	scanf("%d %lld", &n, &k);

	for(int i = 0; i < n; i++)
		scanf("%lld", v+i);

	sum[0] = 0;
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i-1] + v[i-1];

	int p = 0;
	if(k == 1){
		target[p++] = 1;
	}
	else if(k == -1){
		target[p++] = 1;
		target[p++] = -1;
	}
	else for(long long tmp = 1; abs(tmp) <= 1000000000LL; tmp *= k)
		target[p++] = tmp;

	long long ans = 0;
	cnt[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < p; j++){
			long long x = sum[i] - target[j];

			if(!cnt.count(x)) continue;

			ans += cnt[x];
		}
		cnt[ sum[i] ]++;
	}

	printf("%lld\n", ans);

	return 0;
}