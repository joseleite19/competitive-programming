#include <bits/stdc++.h>

#define forn(i, n) for(long long i = 0; i < int(n); i++)
#define fore(i, a, b) for(long long i = int(a); i <= int(b); i++)

using namespace std;

long long vet[300000];
long long vxt[300000];
long long sum[300000];

int main(){

	long long n, m, a, d;
	long long resp = 0;

	scanf("%lld", &n);

	forn(i, n){
		scanf(" %lld%lld", &vet[i], &vxt[i]);
		sum[i] = vet[i] + vxt[i];
	}

	for (long long i = 1; i < n; i++) {
		if (sum[i] >= sum[i - 1]) {
			sum[i] = min(sum[i], sum[i - 1] + 1);
		}
	}
	for (long long i = n - 1; i >= 1; i--) {
		if (sum[i - 1] > sum[i] + 1) {
			sum[i - 1] = sum[i] + 1;
		}
	}
	for (long long i = n - 1; i >= 0; i--) {
		if (sum[i] < vet[i]) {
			printf("-1\n");
			return 0;
		} else {
			resp += sum[i] - vet[i];
		}
	}
	printf("%lld\n", resp);
	for (long long i = 0; i < n; i++)
		printf("%lld ", sum[i]);
	printf("\n");
	
	return 0;

}
/*if ((1 <= fi && fi <= n && se <= d)) {
			aprov = fi;
			lista.push_back(funci*a);

			while (i < n && vet[i] <= lista.back() + d) i++;
			funci = (lista.back() + d) / a;
			i--;
		} else if ((n < fi && (fi - n * a) <= d)) {
			aprov = n;
			lista.push_back(funci*a);

			while (i < n && vet[i] <= lista.back() + d) i++;
			funci = (lista.back() + d) / a;
			i--;
		}*/
