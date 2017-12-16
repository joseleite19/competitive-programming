#include <bits/stdc++.h>

using namespace std;

#define N 50050

typedef long long ll;

int cor[N];
bool vis[N];

bool resp = true;

vector <int> grafo[N];

int n,m,k;

void dfs(int u, int cor_atual){

	vis[u] = true;

	int proxima_cor = cor_atual+1;

	if(proxima_cor == k+1) proxima_cor = 1;

	for(auto v: grafo[u]){
		if(cor[v] == 0){
			cor[v] = proxima_cor;
			dfs(v,proxima_cor);
		}
		else if(cor[v] == cor_atual) resp = false;
	}

}

int main(){

	scanf("%d %d %d", &n, &m, &k);

	while(m--){

		int v1,v2;

		scanf("%d %d", &v1, &v2);

		grafo[v1].push_back(v2);
		grafo[v2].push_back(v1);
	}

	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			cor[i] = 1;
			dfs(i,1);
		}
	}

	if(!resp) printf("-1\n");

	else{

		for(int i = 1; i <= n; i++){
			printf("%d\n",cor[i]);
		}

	}

    return 0;
}
