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
		deque<pair<int, long long> > s;

		for(int i = 0; i < n; i++){
			delta += v[i];
			while(s.size() && s.back().second + delta <= v[i]) s.pop_back();
			s.push_back(make_pair(i, v[i] - delta));

			while(s.size() && s.front().second + delta >= x){
				ans = min(ans, i - s.front().first+1);
				s.pop_front();
			}
		}
		if(ans == n+1) ans = -1;
		printf("%d\n", ans);
	}

	return 0;
}