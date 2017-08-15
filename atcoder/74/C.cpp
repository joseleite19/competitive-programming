#include <bits/stdc++.h>

using namespace std;

long long f(long long w, long long h){
	if(h % 3 == 0) return 0;

	long long a1, a2, a3, ret = 1000000000000000000;
	for(long long t = 1; t < h; t++){
		a1 = w*t;
		a2 = (w/2)*(h-t);
		a3 = (w - w/2)*(h-t);
		ret = min(ret, max(max(a1, a2), a3) - min(min(a1, a2), a3));
		// printf("%lld %lld %lld\n", a1, a2, a3);
	}
	return ret;
}


int main(){
	long long h, w;

	scanf("%lld %lld", &h, &w);

	printf("%lld\n", min(f(h, w), f(w, h)));


	return 0;
}