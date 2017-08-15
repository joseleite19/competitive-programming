#include <bits/stdc++.h>

using namespace std;

typedef pair <int,long long> ii;

vector <ii> grafo[30];

int n;

vector <int> ordem;

vector <bool> vis(30,false);

void bfs(int u){

	queue <int> q;

	q.push(u);

	ordem.push_back(u);

	vis[0] = true;

	while(!q.empty()){

		int u = q.front();

		q.pop();

		for(int i = 0; i < grafo[u].size(); i++){
			ii aux = grafo[u][i];
			int v = aux.first;

			if(!vis[v]){
				vis[v] = true;
				ordem.push_back(v);
				q.push(v);
			}
		}
	}
}

long long dist(int origem, int destino, long long distancia){

	long long ret = 0;
	for(int i = 0; i < grafo[origem].size(); i++){
		ii aux = grafo[origem][i];
		int v = aux.first;
		if(vis[v]) continue;
		vis[v] = true;
		long long peso = aux.second;
		if(v == destino){
			return distancia + peso;
		}
		ret = max(ret, dist(v,destino, distancia + peso));
	}
	return ret;
}

int main(){

	int casos;

	scanf("%d", &casos);

	for(int caso = 1; caso <= casos; caso++){

		scanf("%d", &n);

		ordem.clear();

		for(int i = 0; i < 26; i++){
			grafo[i].clear();
		}

		for(int i = 0; i < n-1; i++){
			char v1,v2;
			long long peso;
			scanf(" %c %c", &v1, &v2);
			scanf("%lld", &peso);
			grafo[v1-'A'].push_back(ii(v2-'A',peso));
			grafo[v2-'A'].push_back(ii(v1-'A',peso));
		}

		for(int i = 0; i < 26; i++ ){
			sort(grafo[i].begin(), grafo[i].end());
		}

		vis.assign(30,false);
		bfs(0);

		long long resp = 0;

		ordem.push_back(0);

		/*for(auto x: ordem){
			cout << x << endl;
		}*/

		for(int i = 0; i < ordem.size()-1; i++){
			vis.assign(30,false);
			vis[ordem[i]] = true;
			resp += dist(ordem[i],ordem[i+1],0);
		}

		//printf("\n");

		printf("Trilha #%d:\nDeslocamento total: %lld\n",caso, resp);

		printf("\n");
	}

	return 0;
}