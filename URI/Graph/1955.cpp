#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	vector<vector<int> > g;
	queue<int> q;

	scanf("%d", &n);

	g.assign(n, vector<int>());

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int x;
			scanf("%d", &x);
			if(!x) g[i].push_back(j);
		}
	}

	set<int> par;
	set<int> impar;

	par.insert(0);

	q.push(0);

	bool dacerto = true;
	vector<bool> vis(n, 0);

	vis[0] = true;

	while(!q.empty()){
		int u = q.front(); q.pop();
		int paridadePai;
		if(par.find(u) != par.end()) paridadePai = 1;
		else paridadePai = 0;

		for(int v : g[u]){
			if(!vis[v]){
				vis[v] = true;
				q.push(v);
			}
			if(paridadePai == 1){
				if(par.find(v) != par.end()){
					dacerto = false;
					break;
				}
				else{
					impar.insert(v);
				}
			}
			else{
				if(impar.find(v) != impar.end()){
					dacerto = false;
					break;
				}
				else{
					par.insert(v);
				}
			}
		}
	}

	printf("%s\n", dacerto ? "Bazinga!" : "Fail!");

	return 0;
}