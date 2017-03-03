#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	long long n, a, b, c;

	scanf("%lld %lld %lld %lld", &n, &a, &b, &c);

	long long ans = 1e18;

	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			for(int k = 0; k < 100; k++){
				if((n + i + 2*j + 3*k) % 4 == 0)
					ans = min(ans, i*a + j*b + k*c);
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
}