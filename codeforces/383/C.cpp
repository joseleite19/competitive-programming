#include <bits/stdc++.h>

using namespace std;

int c[200], n;

int dfs(int u, int t){
	if(t == 0) return u;
	return dfs(c[u], t-1);
}

int main(){
	int x;

	scanf("%d", &n);


	for(int i = 0; i < n; i++){
		scanf("%d", &x), x--;
		c[i] = x;
	}

	int ans = -1;

	for(int t = 1; t <= 3*n; t++){
		bool q = true;
		for(int u = 0; u < n && q; u++){
			if(dfs( dfs(u, t), t ) != u){
				q = false;
			}
		}
		if(q){
			ans = t;
			break;
		}
	}

	printf("%d\n", ans);
}



// 0 0 0 1
// 0 0 0 1
// 0 0 0 1
// 0 0 0 1