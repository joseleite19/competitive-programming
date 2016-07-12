#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
int n, m;
vector<int> bip;
bool possible;

void check(int i){
	queue<int> q;
	q.push(i);
	bip[i] = 0;

	while(!q.empty() && possible){
		int u = q.front(); q.pop();
		for(int v : g[u]){
			if(bip[u] == bip[v])
				possible = false;
			else if(bip[v] == 2){
				bip[v] = 1^bip[u];
				q.push(v);
			}
		}
	}
}

int main(){

	scanf("%d %d", &n, &m);

	g.assign(n+1, vector<int>());

	int u, v = 1;
	for(int i = 0; i < m; i++){
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	possible = true;

	bip.assign(n+1, 2);

	for(int i = 1; i <= n; i++)
		if(g[i].size() && bip[i] == 2)
			check(i);

	if(!possible) printf("-1\n");
	else{
		vector<int> v1, v2;
		for(int i = 1; i <= n; i++){
			if(g[i].size() == 0) continue;
			if(bip[i] == 1) v1.push_back(i);
			else v2.push_back(i);
		}

		printf("%d\n%d", v1.size(), v1[0]);
		for(int i = 1; i < v1.size(); i++)
			printf(" %d", v1[i]);
		printf("\n");

		printf("%d\n%d", v2.size(), v2[0]);
		for(int i = 1; i < v2.size(); i++)
			printf(" %d", v2[i]);
		printf("\n");
	}

	return 0;
}