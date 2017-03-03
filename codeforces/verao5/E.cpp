#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

long long ft[10005];
int n;

void add(int x, long long v){
	for(; x <= n; x += x & -x)
		ft[x] += v;
}

long long query(int x){
	long long ans = 0;
	for(; x > 0; x -= x&-x)
		ans += ft[x];
	return ans;
}


int main(){

	long long v[10000];

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%lld", v+i);

	sort(v, v+n);

	long long base = v[0];

	int qnt = 1;
	while(1){
		int id = upper_bound(v, v + n, base) - v;
		if(id == n) break;
		qnt++;
		base += v[id];
	}
	printf("%d\n", qnt);


	// map<int, int> mm;

	// for(int i = 0; i < n; i++){
	// 	mm[ v[i] ]++;
	// }

	// int i = 0;
	// for(map<int, int>::iterator it = mm.begin(); it != mm.end(); it++){
	// 	v[i++] = it->ff;
	// 	// printf("..%d %d\n", it->ff, it->ss);
	// 	// if(it->ss > 1){
	// 	// 	v[i++] = it->ff;
	// 	// }
	// }
	// n = i;

	// long long sum[10000];

	// sum[0] = v[0];
	// for(int i = 1; i < n; i++)
	// 	sum[i] += sum[i-1] + v[i];

	// // for(int i = 0; i < n; i++)
	// // 	printf("%d %lld\n", i, sum[i]);

	// int qnt = 1;

	// int base = v[n-1];
	// while(1){
	// 	int id = lower_bound(sum, sum + n, base) - sum;
	// 	// printf("id %d %d\n", id, v[id]);
	// 	// sum[id] = v[id];
	// 	// printf("%d %d %lld\n", base, id, sum[id]);
	// 	if(id == 0){
	// 		// if(v[id] < base) qnt++;
	// 		// if(v[id] == base && v[id] == v[id+1]) qnt++;
	// 		break;
	// 	}
	// 	id--;
	// 	// printf("..%d\n", id);
	// 	qnt++;
	// 	base = v[id];
	// }

	// printf("%d\n", qnt);

	return 0;
}