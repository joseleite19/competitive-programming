#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD 1000000007

using namespace std;

int v[100005];

set<pair<int, int> > s[1000006];

long long fat[1000006];

int main(){
	int n, m, x;

	fat[0] = 1;

	for(int i = 1; i < 1000006; i++)
		fat[i] = (i*fat[i-1]) % MOD;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		scanf("%d", &x);

		for(int j = 0; j < x; j++)
			scanf("%d", v+j);
		map<int, int> mm;
		for(int j = 0; j < x; j++)
			mm[ v[j] ]++;

		for(map<int, int>::iterator it = mm.begin(); it != mm.end(); it++)
			s[ it->ff ].insert(mp(i, it->ss));
	}

	map<set<pair<int, int> >, int> mm;

	for(int i = 1; i <= m; i++)
		mm[ s[i] ]++;

	long long ans = 1;

	for(map<set<pair<int, int> >, int>::iterator it = mm.begin(); it != mm.end(); it++)
		ans = (ans * fat[ it->ss ]) % MOD;

	printf("%lld\n", ans);

	return 0;
}