#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAXV 510
#define MAXE 250000

struct point{
	int x, y;
	double dist(point a){
		return sqrt((x-a.x)*(x-a.x) + (y-a.y)*(y-a.y));
	}
};

int set[MAXV], ranked[MAXV];

void make_set(int x){
	set[x] = x;
	ranked[x] = 0;
}

int find_set(int x){
	return (x == set[x] ? x : set[x] = find_set(set[x]));
}

void union_set(int x, int y){
	int a = find_set(x),
	b = find_set(y);

	if(ranked[a] > ranked[b]) set[b] = a;
	else{
		set[a] = b;
		if(ranked[a] == ranked[b]) ranked[b]++;
	}
}


struct edge{
	point x, y;
	double z;
	int i, j;
	bool operator<(const edge & e) const{
		return z < e.z;
	}
	edge(point a, point b, int i, int j) : x(a), y(b), i(i), j(j), z(a.dist(b)){};
	edge () {};
};

double dist[MAXV+10];
int vis[MAXV+10];

int main(){
	int n, m, c;
	edge e[MAXE];
	point p[MAXV];

	scanf("%d", &c);

	while(c--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d %d", &p[i].x, &p[i].y);
			make_set(i);
		}
		vector<vector<edge> > g(n);
		int k = 0;
		for(int i = 0; i < n; i++){
			dist[i] = 1e50;
			for(int j = i+1; j < n; j++){
				e[k++] = edge(p[i], p[j], i, j);
				g[i].push_back(edge(p[i], p[j], i, j));
				g[j].push_back(edge(p[i], p[j], j, i));
			}
		}

		priority_queue<pair<double, int> > q;

		q.push(make_pair(0, 0));
		dist[0] = 0;
		memset(vis, 0, sizeof vis);

		double mst = 0;
		while(!q.empty()){
			double d = -q.top().first;
			int u = q.top().second; q.pop();
			if(d > dist[u]) continue;
			if(vis[u]) continue;
			vis[u] = 1;
			// printf("%d %lf\n", u, d);
			mst += d;
			for(auto x : g[u]){
				int v = x.j;
				// printf("%d->%d\n", u, v);
				if(dist[v] > x.z){
					dist[v] = x.z;
					q.push(make_pair(-dist[v], v));
				}
			}
		}

		// sort(e, e + k);
		// for(int i = 0; i < k; i++){
		// 	if(find_set(e[i].i) != find_set(e[i].j)){
		// 		mst += e[i].z;
		// 		union_set(e[i].i, e[i].j);
		// 	}
		// }
		printf("%.2lf\n", mst/100);
	}

	return 0;
}