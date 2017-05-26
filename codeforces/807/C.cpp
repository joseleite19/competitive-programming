#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;
long long x, y, p, q;

long long f(long long mid){
    return p*mid >= x && (q-p)*mid >= y-x;
}

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%lld %lld %lld %lld", &x, &y, &p, &q);

		if(p == 0){
			printf("%d\n", x == 0 ? 0 : -1);
			continue;
		}
		if(p == q){
			printf("%d\n", x == y ? 0 : -1);
			continue;
		}

        long long hi = 1000000000, lo = 0;
        if(!f(hi)){ printf("-1\n"); continue; }

        while(lo+1 < hi){
            int mid = (lo + hi) / 2;

            if(f(mid)) hi = mid;
            else lo = mid+1;
        }
        if(!f(lo)) lo++;
        printf("%lld\n", lo*q - y);
	}




	return 0;
}
