#include <bits/stdc++.h>

using namespace std;

int main(){
	map<long long, vector<int> > indexes;
	int a[200005];

	int n, k;
	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i++){
		scanf("%d", a+i);
		indexes[ a[i] ].push_back(i);
	}
	for(pair<const long long, vector<int> > & v : indexes)
		sort(v.second.begin(), v.second.end());

	long long ans = 0;
	for(int i = 0; i < n; i++){
		if(a[i] % k) continue;
		auto &v = indexes[ (long long) k * a[i] ];
		auto &v2 = indexes[ a[i] / k ];
		
		int low = (int) (lower_bound(v.begin(), v.end(), i+1) - v.begin());
		int up = (int) (upper_bound(v2.begin(), v2.end(), i-1) - v2.begin());
		ans += (v.size() - low)*(up);
	}

	printf("%lld\n", ans);

	return 0;
}
