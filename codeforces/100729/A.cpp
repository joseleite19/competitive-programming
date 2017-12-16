#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;


long long vet[300000];

int main(){
	long long t = 0;

	vector<pair<long long, pair<long long, long long> > > newton;

	long long fim = 300000 - 1;
	for(long long i = 1; i < 300000; i++){
		vet[(int)i] = i * (i + 1) / 2;
	}

	int j = 3;
	int lim = 2;

	long long DEZaQUINZE = 1000000000000000;

	while (fim > j) {
		for (int i = 2; i <= fim; i++) {
			vet[i] += vet[i - 1];
			if (vet[i] > DEZaQUINZE) {
				fim = i - 1;
				break;
			}
			if (i > j)
				newton.push_back(mp(vet[i], mp(i+j-1, j)));
		}
		j++;
	}
	// printf("asdasd\n");

	sort(newton.begin(), newton.end());

	scanf("%lld", &t);

	while(t--){
		long long m;

		scanf("%lld", &m);
		vector< pair< long long, long long > > ans;
		ans.push_back(mp(m, 1));
		if(1 != m-1) ans.push_back(mp(m, m-1));

		long long delta = 1 + 8*m;

		long long tmp = (long long)sqrt(delta);

		if(tmp*tmp == delta && tmp & 1 && m != 3){
			long long x = (1 + tmp) / 2;
			ans.push_back(mp(x, 2));
			if(2 != x-2) ans.push_back(mp(x, x-2));
		}

		for(auto x = lower_bound(newton.begin(), newton.end(), mp(m, mp(0LL, 0LL))); x != newton.end() && x->ff == m; x++){
			ans.push_back(mp(x->ss.ff, x->ss.ss));
			if(x->ss.ss != x->ss.ff - x->ss.ss) ans.push_back(mp(x->ss.ff, x->ss.ff - x->ss.ss));
		}

		sort(ans.begin(), ans.end());

		printf("%d\n(%lld,%lld)", (int)ans.size(), ans[0].ff, ans[0].ss);

		for(int i = 1; i < (int)ans.size(); i++)
			printf(" (%lld,%lld)", ans[i].ff, ans[i].ss);

		printf("\n");
	}


	return 0;
}
// 562949953421312
// 576460752303423488