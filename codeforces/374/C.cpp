#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, t;

vector<pair<int, int> > g[5005];
vector<pair<int, int> > g2[5005];


stack<int> ss;
pair<int,int> dist[5005];
pair<int,int> dist2[5005];
int parent[5005];

set<pair<int, int> > m[5005];

int f(){

	priority_queue< pair<int, pair<int, int> > > q;

	q.push(mp(1, mp(0, 1)));

	while(!q.empty()){
		int u = q.top().ss.ss;
		int tmp = -q.top().ss.ff;
		int d = q.top().ff; q.pop();

		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i].ff;
			int dd = g[u][i].ss;

			if(dd + tmp <= t){
				// printf("das %d %d %d\n", v, d+1, tmp);
				if(dist[v] < mp(d+1, dd+tmp)){
					dist[v] = mp(d+1, dd+tmp);
					m[v].insert(dist[v]);
					q.push(mp(d+1, mp(-(dd+tmp), v)));
				}
			}
		}
	}

	while(!q.empty()) q.pop();

	q.push(mp(1, mp(0, n)));
	
	while(!q.empty()){
		int u = q.top().ss.ss;
		int tmp = -q.top().ss.ff;
		int d = q.top().ff; q.pop();

		for(int i = 0; i < g2[u].size(); i++){
			int v = g2[u][i].ff;
			int dd = g2[u][i].ss;

			if(dd + tmp <= t){
				// printf("das %d %d %d\n", v, d+1, tmp);
				if(dist2[v] < mp(d+1, dd+tmp)){
					dist2[v] = mp(d+1, dd+tmp);
					q.push(mp(d+1, mp(-(dd+tmp), v)));
				}
			}
		}
	}

	if(dist[n].ss != dist2[1].ss){
		printf("#%d %d %d %d\n", dist2[1].ss, dist[n].ss, dist2[1].ff, dist[n].ff);
	}

	int u = n, total = dist[n].ss;
	ss.push(u);
	int dddd = dist[n].ff;
	
	for(int i = 0; i < dist[n].ff-2; i++){
		for(int i = 0; i < g2[u].size(); i++){
			int v = g2[u][i].ff;
			int dd = g2[u][i].ss;

			if(m[v].find(mp(dddd-1, total - dist2[u].ss-dd)) != m[v].end()){
				dddd = dddd-1;
				u = v;
				break;
			}
		}
		ss.push(u);
	}
	ss.push(1);
	return dist[n].ff;
}

int main(){
	int a, b, c, m;
	scanf("%d %d %d", &n, &m, &t);

	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back(mp(b,c));
		g2[b].push_back(mp(a,c));
	}

	printf("%d\n", f());
	vector<int> v;
	b = 1;
	while(!ss.empty()){
		v.push_back(ss.top()); ss.pop();
	}
	printf("%d", v[0]);
	for(int i = 1; i < v.size(); i++){
		printf(" %d", v[i]);
	}
	printf("\n");

	return 0;
}