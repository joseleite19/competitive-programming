#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, v[100005];
long long sum[100005];

int main(){

	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		scanf("%d", v+i);

	sum[0] = 0;
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i-1] + v[i];
	sum[n+1] = sum[n];

	long long ans = sum[n];
	set<int> s;
	set<pair<long long,int> > s2;
	int x;

	s2.insert(mp(sum[n], 0));
	s.insert(n+1);
	s.insert(0);
	set<pair<long long,int> >::iterator it;
	set<int>::iterator it2;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		it2 = s.lower_bound(x);
		it2--;
		int tmp = *it2;
		if(s.find(x) != s.end()){
			printf("%lld\n", ans);
			continue;
		}
		int tmp1 = *s.upper_bound(x);
		
		// printf("##%d %d %d %d %d\n", tmp, tmp1, tmp2, sum[x-1] - sum[tmp], sum[tmp1-1] - sum[x]);
		
		s2.erase(mp(sum[tmp1-1] - sum[tmp], tmp));
		s2.insert(mp(sum[x-1] - sum[tmp], tmp));
		s2.insert(mp(sum[tmp1-1] - sum[x], x));
		s.insert(x);
		it = s2.upper_bound(mp(1e18, 1e18));
		it--;
		ans = it->ff;
		printf("%lld\n", ans);
	}

	return 0;
}