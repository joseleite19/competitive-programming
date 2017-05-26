#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

long long ans;
int n;
long long v[502];
long long mn;

pair<long long, pair<long long, long long> > euclidesExt(long long  a, long long b){
	if(b == 0) return mp(a, mp(1, 0));

	pair<long long, pair<long long, long long> > ret = euclidesExt(b, a%b);
	pair<long long, long long> tmp = ret.ss;

	ret.ss.ff = tmp.ss;
	ret.ss.ss = tmp.ff - tmp.ss*(a/b);

	return ret;
}

bool f(long long k){
	for(int i = 0; i < n; i++){
		long long q = v[i]/k;
		long long r = v[i]%k;
		if(q < r) return false;
	}
	return true;
}

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%lld", v+i);

	mn = 1000000000000;

	for(int i = 0; i < n; i++)
		mn = min(mn, v[i]);

	long long hi = 1000000000000, lo = 1, k;

	while(lo <= hi){
		long long mid = (lo + hi) / 2;
		if(f(mid)) k = mid, lo = mid+1;
		else hi = mid-1;
	}

	pair<long long, long long> p = euclidesExt(k, k+1).ss;
	printf("%lld %lld\n", p.ff, p.ss);
	if(p.ff < 0){

	}
	p.ss--;
	p.ff += 2;
	assert(p.ff >= 0);
	assert(p.ss >= 0);
	for(int i = 0; i < n; i++){
		// ans += (v[i] + k) / (k+1);
		ans += p.ff * v[i];
		ans += p.ss * v[i];
	}
	printf("%lld\n", ans);

	// for(int i = 1; i < 20; i++)
	// 	printf("%d %d\n", i, f(i));




	return 0;
}