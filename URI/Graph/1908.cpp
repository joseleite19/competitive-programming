#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k, l, x;
	// vector<vector<int> > itinerario;
	vector<vector<int> > g;

	scanf("%d %d", &n, &k);
	// itinerario.assign(n+1, vector<int>());
	g.assign(n+1, vector<int>());

	for(int i = 0; i < k; i++){
		scanf("%d", &l);
		vector<int> itinerario;
		while(l--){
			scanf("%d", &x);
			itinerario.push_back(x);
		}
		for(int j = 0; j < itinerario.size(); j++){
			for(int k = 0; k < itinerario.size(); k++){
				g[ itinerario[j] ].push_back( itinerario[k] );
			}
		}
	}

	vector<int> dist(n+1, 1000000000);
	queue<int> q;
	q.push(1);
	dist[1] = 0;

	while(!q.empty()){
		int u = q.front(); q.pop();

		for(int v : g[u]){
			if(dist[v] == 1000000000){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	printf("%d\n", dist[n]);

	return 0;
}