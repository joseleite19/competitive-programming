#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

inline int lg(long long x){
	if(x == 0) return 1;
	return 64 - __builtin_clzll(x);
}

inline long long len(long long x){
	return (1LL << lg(x)) - 1;
}

long long f(long long limit, long long x, long long id){
	if(id > limit) return 0;
	if(id + len(x)-1 <= limit) return x;

	long long ans = 0;

	if(id + len(x/2) <= limit) ans += (x & 1);

	ans += f(limit, x/2, id);
	ans += f(limit, x/2, id+len(x/2)+1);
	return ans;
}

int h(long long x, long long id){

	long long tmp = (len(x)+1)/2;
	if(tmp == id) return x & 1;
	
	return h(x/2, id % tmp);
}

int main(){

	long long n, l, r;

	scanf("%lld %lld %lld", &n, &l, &r);

	printf("%lld\n", f(r, n, 1) - f(l-1, n, 1));

	return 0;
}