#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int c, n;

	long long x[10004], y[10004];

	pair<long long, long long> p[10004];

	scanf("%d", &c);

	while(c--){
		map<pair<long long, long long>, int> cnt;

		scanf("%d", &n);

		for(int i = 0; i < n; i++){
			scanf("%lld %lld", &p[i].ff, &p[i].ss);
			tie(x[i], y[i]) = p[i];
			cnt[ p[i] ] = 1;
		}

		sort(x, x + n);
		sort(y, y + n);

		long long xx, yy;

		xx = x[(n-1)/2] + x[n/2];
		yy = y[(n-1)/2] + y[n/2];

		// printf("%lld %lld\n", xx, yy);

		bool deucerto = true;
		for(int i = 0; i < n; i++){
			long long tmp1, tmp2;
			tmp1 = xx - p[i].ff;
			tmp2 = yy - p[i].ss;
			// printf("%lld %lld\n", tmp1, tmp2);
			if(!cnt[mp(tmp1, tmp2)])
				deucerto = false;
			
		}
		printf("%s\n", deucerto ? "yes" : "no");
	}

	return 0;
}
