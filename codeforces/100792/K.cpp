#include <bits/stdc++.h>

using namespace std;

vector<set<int> > g;
vector<int>outgoing;
int main(){
	int n, m, a, b;

	scanf("%d %d", &n, &m);

	g.assign(n+1, set<int>());
	outgoing.assign(n+1, 0);


	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		if(g[b].insert(a).second)
			outgoing[a]++;
	}

	priority_queue<int> q;

	for(int i = 1; i <= n; i++)
		if(!outgoing[i])
			q.push(i);

	stack<int> s;
	while(!q.empty()){
		int u = q.top(); q.pop();
		s.push(u);
		for(int v : g[u]){
			outgoing[v]--;
			if(!outgoing[v]) q.push(v);
		}
	}

	printf("%d", s.top());
	s.pop();

	while(!s.empty())
		printf(" %d", s.top()), s.pop();
	printf("\n");

	return 0;
}