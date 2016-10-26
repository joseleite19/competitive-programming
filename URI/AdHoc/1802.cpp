#include <bits/stdc++.h>

using namespace std;

int main(){
	multiset<int> hack;

	int p, m, q, f, b;
	int v[5][10];

	scanf("%d", &p);
	for(int i = 0; i < p; i++)
		scanf("%d", &v[0][i]);

	scanf("%d", &m);
	for(int i = 0; i < m; i++)
		scanf("%d", &v[1][i]);

	scanf("%d", &q);
	for(int i = 0; i < q; i++)
		scanf("%d", &v[2][i]);

	scanf("%d", &f);
	for(int i = 0; i < f; i++)
		scanf("%d", &v[3][i]);

	scanf("%d", &b);
	for(int i = 0; i < b; i++)
		scanf("%d", &v[4][i]);

	for(int i = 0; i < p; i++) for(int j = 0; j < m; j++)
		for(int k = 0; k < q; k++) for(int qq = 0; qq < f; qq++)
			for(int w = 0; w < b; w++)
				hack.insert(v[0][i] + v[1][j] + v[2][k] + v[3][qq] + v[4][w]);
	
	int k;

	scanf("%d", &k);

	long long ans = 0;
	
	while(k--){
		ans += *prev(hack.end());
		hack.erase(prev(hack.end()));
	}
	printf("%lld\n", ans);

	return 0;
}