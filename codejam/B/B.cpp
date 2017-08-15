#include <bits/stdc++.h>

using namespace std;

int cnt;
long long v[4686826];
set<long long> s;
void bc(long long num, int last){
	if(num >= 1000000000000000000) return;
	v[cnt++] = num;

	for(int i = last; i <= 9; i++){
		long long x = 10*num + i;
		bc(x, i);
	}
}

int main(){

	int t;
	long long n;

	bc(0, 1);
	sort(v, v+cnt);

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		scanf("%lld", &n);
		printf("Case #%d: %lld\n", tc, *(upper_bound(v, v+cnt, n)-1));
	}

	return 0;
}