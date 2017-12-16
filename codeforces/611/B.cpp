#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

long long limit = 3000000000000000000;
vector<long long> pre;

int f(long long n){
	int ans = 0;
	set<int> ss;
	for(int size = 0; (1LL << size) <= 2*n; size++){
		long long tmp = (1LL << size) - 1;
		for(int t = 0; t < size-1; t++){
			long long tmp2 = tmp - (1LL << t);
			// printf("%lld\n", tmp2);
			if(tmp2 >= 0 && tmp2 <= n) ss.insert(tmp2);
		}
	}

	return (int)ss.size();
}

int f(long long a, long long b){
	printf("%lld %lld %d %d %d\n", a, b, f(a), f(b), f(a-1));
	return f(b) - f(a-1);
}

int main(){
	long long a, b;

	// printf("%lld\n", (~(1LL << 63)) & ((1 << 2)-1) & (~(1 << 1)));

	// printf("%d %d\n", 1, f(1));

	for(int i = 0; i <= 20; i++)
		printf("%d %d\n", i, f(i));

	scanf("%lld %lld", &a, &b);

	printf("%d\n", f(a, b));

	return 0;
}