#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int dp[1005][2];
bool mark[1005][2];
int dist[1005];
vector<int> g[1005];

int f(int u, int who){
	if(mark[u][who]) return dp[u][who];
	mark[u][who] = 1;

	if(!g[u].size()){
		return dp[u][who] = who;
	}

	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(dist[v] == dist[u] + 1){
			if(f(v, 1^who) != who){
				return dp[u][who] = 1^who;
			}
		}
	}
	return dp[u][who] = who;
}


int main(){

	int n, m;

	scanf("%d %d", &n, &m);

	int a, b;
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	queue<int> q;

	q.push(1);

	dist[1] = 1;

	while(!q.empty()){
		int u = q.front(); q.pop();

		for(int i = 0; i < (int)g[u].size(); i++){
			int v = g[u][i];
			if(!dist[v]){
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}

	printf("%s\n", !f(1, 0) ? "Nikolay" : "Vladimir");


	return 0;
}