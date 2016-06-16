#include <bits/stdc++.h>

using namespace std;

vector<vector< pair<int,int> > > g;

int main(){
	int c, v, x, y, z;

	while(scanf("%d %d", &c, &v) == 2){
		g.assign(c+1, vector<pair<int,int>>());

		for(int i = 0; i < v; i++){
			scanf("%d %d %d", &x, &y, &z);
			g[x].push_back(make_pair(y, z));
			g[y].push_back(make_pair(x, z));
		}

		priority_queue<pair<pair<int, int>, int> >q; // pair<pair<dist, state>, vertex>
		vector<vector<long long>> d(2, vector<long long>(c+1, 1e9));
		q.push(make_pair(make_pair(0, 0), 1));

		long long ans = -1;
		while(!q.empty()){
			int dist = -q.top().first.first;
			int state = q.top().first.second;
			int v = q.top().second; q.pop();
			if(v == c && state == 0){
				ans = dist;
				break;
			}
			int nextState = 1^state;
			for(pair<int, int> &u : g[v]){
				if(dist + u.second < d[nextState][u.first]){
					d[nextState][u.first] = dist + u.second;
					q.push(make_pair(make_pair(-d[nextState][u.first], nextState), u.first));
				}
			}
		}
		printf("%lld\n", ans);
	}



	return 0;
}