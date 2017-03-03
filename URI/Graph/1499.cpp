#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int dist1[100000], dist2[100000];
long long sum[100000];
vector<vector<int> > g;

int longe;

int bfs(int source, int *dist){
	dist[source] = 0;
	longe = source;
	queue<int> q;
	q.push(source);

	while(!q.empty()){
		int u = q.front(); q.pop();
		
		for(int i = 0; i < (int)g[u].size(); i++){
			int v = g[u][i];
			if(dist[v] == -1){
				dist[v] = dist[u]+1;
				if(dist[v] > dist[longe]) longe = v;
				q.push(v);
			}
		}
	}
}

int main(){
	int n[2], a, b;
	long long d;

	while(scanf("%d %d", n, n+1) == 2){
		d = 0;

		vector<long long> vet1, vet2;
		for(int j = 0; j < 2; j++){
			vet1.assign(n[j], 0);
			g.assign(n[j], vector<int>());

			for(int i = 0; i < n[j] - 1; i++){
				scanf("%d %d", &a, &b); a--; b--;
				g[a].push_back(b);
				g[b].push_back(a);
			}


			memset(dist1, -1, sizeof dist1);
			bfs(0, dist1);
			
			memset(dist1, -1, sizeof dist1);
			bfs(longe, dist1);
			
			memset(dist2, -1, sizeof dist2);
			bfs(longe, dist2);
			
			d = max(d, (long long)dist2[longe]);

			for(int i = 0; i < n[j]; i++)
				vet1[i] = max(dist1[i], dist2[i]);

			swap(vet1, vet2);
		}

		sort(vet2.begin(), vet2.end());

		sum[0] = 0;
		for(int i = 0; i < (int)vet2.size(); i++)
			sum[i+1] = sum[i] + vet2[i];

		long long tot = sum[ vet2.size() ];
		long long ans = 0;

		for(int i = 0; i < (int)vet1.size(); i++){
			int id = int(lower_bound(vet2.begin(), vet2.end(), d - (vet1[i]+1)) - vet2.begin());
			ans += tot - sum[id] + (n[1] - id)*(vet1[i]+1) + id*d;
		}
		printf("%.3lf\n", (double)ans/(n[0] * n[1]));
	}

	return 0;
}