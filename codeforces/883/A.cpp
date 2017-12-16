#include <bits/stdc++.h>

#define ll unsigned long long

using namespace std;

ll funci = 1;

ll vet[400000];

ll lista;

int main(){

	ll n, m, a, d;

	ll resp = 0;

	scanf("%llu%lld%lld%lld", &n, &m, &a, &d);

	for(ll i = 0; i < m; i++){
		ll x;
		scanf(" %llu", &x);
		vet[i] = x;
	}
	ll r = d / a;
	r++;
	for (ll i = 0; i < m;) {
//printf("!%llu\n", i);
		ll tmp = vet[i] - d;
		if (tmp < 0) tmp = 0;

		ll firs = tmp/a + (tmp%a ? 1 : 0);

//printf("@%llu\n", i);
		ll secon = vet[i] / a;

		if (secon > n) secon = n;

		if (funci <= n && secon >= funci && firs <= secon) {
//printf("#%llu %d %d\n", funci, firs, secon); fflush(stdout);
//printf("$%llu\n", i);
			if (firs < funci) firs = funci;
			if (firs <= n) {
				ll qnt = firs - funci;
				ll t = qnt / r;
				resp += t;
//printf("%llu\n", i);
				funci += t * r;
				if (funci < firs) {
					resp++;
					funci += r;
				}
//printf("%llu\n", i);
			}

			if (firs <= n && funci <= secon) {
				resp++;
	//printf("!%llu %lld\n", resp, funci);
				lista = funci*a;
//printf("%llu\n", i);
				funci += r;
			} else {
				resp++;
	//printf("@%llu %lld\n", resp, funci);
				lista = vet[i];
				funci = (vet[i] + d) / a;
				funci++;
//printf("%llu\n", i);
			}
		} else {
			ll qnt = vet[i] / a;
			qnt = qnt - funci + 1;
			ll t = qnt / r;
			resp += t;
			resp++;
	//printf("#%llu %lld\n", resp, funci);
			lista = vet[i];
			funci = (vet[i] + d) / a;
			funci++;

		}

//printf("%llu.\n", i);
		while (i < m && vet[i] <= lista + d) i++;//, printf("%llu\n", i);
//printf("%llu.\n", i);
	}
	//printf("%llu %lld\n", resp, funci);
	if (funci <= n) {
		ll qnt = n - funci + 1;
		ll t = qnt / r + (qnt%r ? 1 : 0);
		resp += t;
	}

	printf("%llu\n", resp);
//	for (ll i : lista) printf("%llu\n", i);
	
	return 0;

}
/*if ((1 <= fi && fi <= n && se <= d)) {
			aprov = fi;
			lista = funci*a);

			while (i < n && vet[i] <= lista.back() + d) i++;
			funci = (lista.back() + d) / a;
			i--;
		} else if ((n < fi && (fi - n * a) <= d)) {
			aprov = n;
			lista = funci*a);

			while (i < n && vet[i] <= lista.back() + d) i++;
			funci = (lista.back() + d) / a;
			i--;
		}*/
