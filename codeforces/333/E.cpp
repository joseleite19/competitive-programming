#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000

using namespace std;

int mat[405][405], grau[405];

int main(){

	int n, m, a, b;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		mat[a][b] = mat[b][a] = 1;
		grau[a]++;
		grau[b]++;
	}

	if(grau[n] == n){
		printf("-1\n");
		return 0;
	}
	int inv = 1^mat[1][n];

	queue<int> q;
	int dist[405];

	memset(dist, -1, sizeof dist);

	dist[1] = 0;
	q.push(1);

	while(!q.empty()){
		int u = q.front(); q.pop();

		for(int i = 1; i <= n; i++){
			if(inv ^ mat[u][i] && dist[i] == -1){
				dist[i] = dist[u] + 1;
				q.push(i);
			}
		}
	}

	printf("%d\n", dist[n]);
	return 0;
}