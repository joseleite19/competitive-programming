#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, v[10005], c[10005];

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		scanf("%d", v + i);

	for(int i = 0; i < m; i++)
		scanf("%d", c + i);

	int caixa[10005];

	memset(caixa, 0, sizeof caixa);

	for(int i = 0; i < m; i++){
		int id = 0;
		for(int j = 0; j < n; j++)
			if(caixa[j] < caixa[id])
				id = j;
		caixa[id] += v[id]*c[i];
	}
	int total = 0;

	for(int i = 0; i < n; i++)
		total = max(total, caixa[i]);

	printf("%d\n", total);

	return 0;
}