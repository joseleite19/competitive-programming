#include <bits/stdc++.h>

using namespace std;

int n, f[100005], m, g[1000006], h[1000006];

int main(){

	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		scanf("%d", f+i);

	bool can = true;
	for(int i = 1; i <= n; i++){
		if(g[i] && g[ f[i] ] && g[i] != g[ f[i] ]) can = false;
		if(g[i] && g[ f[i] ]) continue;
		else if(g[i]) g[ f[i] ] = g[i];
		else if(g[ f[i] ]) g[i] = g[ f[i] ];
		else g[i] = g[ f[i] ] = ++m;
	}

	for(int i = 1; i <= n; i++){
		if(h[ g[i] ]){
			if(h[ g[i] ] != f[i]) can = false;
			continue;
		}
		h[ g[i] ] = f[i];
	}

	if(!can){
		printf("-1\n");
		return 0;
	}

	printf("%d\n", m);

	for(int i = 1; i <= n; i++)
		printf("%d ", g[i]);
	printf("\n");

	for(int i = 1; i <= m; i++)
		printf("%d ", h[i]);
	printf("\n");


	return 0;
}