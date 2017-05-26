#include <bits/stdc++.h>

using namespace std;

int t, n, x;
long long v[500005];

int main(){

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		scanf("%d %d", &n, &x);

		for(int i = 0; i < n; i++)
			scanf("%lld", v+i);

		int ans = n+1;

		long long delta = 0;
		vector<pair<int, long long> > s;

		for(int i = 0; i < n; i++){
			delta += v[i];
			while(s.size() && s.back().second + delta <= v[i]) s.pop_back();
			s.push_back(make_pair(i, v[i] - delta));

			int hi = s.size() - 1, lo = 0;
			int tmp = -1;

			while(lo <= hi){
				int mid = (lo + hi) / 2;
				if(s[mid].second + delta >= x){
					lo = mid+1;
					tmp = max(tmp, mid);
				}
				else hi = mid-1;
			}
			if(tmp != -1) ans = min(ans, i - s[tmp].first+1);
		}
		if(ans == n+1) ans = -1;
		printf("%d\n", ans);
	}

	return 0;
}