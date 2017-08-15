#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int v[100];
multiset<long long> mat[100];
multiset<long long>::iterator tmp[100];

int take(long long k){
	long long L, R;
	for(int i = 0; i < n; i++){
		L = (9*k*v[i] + 9) / 10;
		R = 11*k*v[i]/10;
		// printf("%d %lld %lld\n", i, L, R);

		int j;
		auto it = mat[i].lower_bound(L);
		if(it == mat[i].end()) return 0;
		if(*it > R) return 0;
		tmp[i] = it;
		// for(j = 0; j < m; j++)
		// 	if(L <= mat[i][j] && mat[i][j] <= R)
		// 		break;
	}

	for(int i = 0; i < n; i++)
		mat[i].erase(tmp[i]);

	return 1;
}

int main(){

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++)
			mat[i].clear();

		for(int i = 0; i < n; i++)
			scanf("%d", v+i);

		long long x;
		long long ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				scanf("%lld", &x);
				mat[i].insert(x);
			}
		
		for(long long k = 1; k <= 1000000; k++){
			while(take(k))
				ans++;
		}
		// printf("%d\n", take(10));
		
		printf("Case #%d: %lld\n", tc, ans);
	}

	return 0;
}