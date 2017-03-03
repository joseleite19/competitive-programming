#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int f(int n){
	// printf("..%d\n", n);
	if(n <= 0) return 0;
	if(n == 1) return 1;
	if(n == 2) return 3;
	if(n == 3) return 5;

	return 2*f(n-3) + 2*f(2) + 1;
}

int bfs(int n){
	map< vector<vector<int> > , int > m;
	queue<pair< vector<vector<int> >, int> > q;
	vector<vector<int> > v;
	v.assign(4, vector<int>());
	for(int i = n; i > 0; i--)
		v[0].push_back(i);
	// v[0].push_back(8);
	// v[0].push_back(7);
	// v[0].push_back(6);
	// v[0].push_back(5);
	// v[0].push_back(4);
	// v[0].push_back(3);
	// v[0].push_back(2);
	// v[0].push_back(1);
	m[v] = 0;
	q.push(mp(v, 0));

	swap(v[0], v[3]);

	while(!q.empty()){
		vector<vector<int> > u = q.front().ff;
		int d = q.front().ss; q.pop();
		if(u == v) break;
		if(m[u] != d) continue;

		for(int i = 0; i < 4; i++){
			if(u[i].size() == 0) continue;
			for(int j = 0; j < 4; j++){
				if(i == j) continue;
				if(u[j].size() > 0 && u[i].back() > u[j].back()) continue;
				vector<vector<int> > newv = u;
				newv[j].push_back(newv[i].back());
				newv[i].pop_back();
				if(m.count(newv)) continue;
				m[ newv ] = m[u] + 1;
				q.push(mp(newv, m[ newv ]));
			}
		}
	}
	return m[v];
}

int main(){
	printf("%d %d\n", f(10), bfs(10));
	// int n;

	// scanf("%d", &n);

	// printf("%d\n", f(n));

	return 0;
}