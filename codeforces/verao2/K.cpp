#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

map<pair<int, pair<int, int> >, int> vai;
map<int, pair<int, pair<int, int> > > volta;

map<pair<int, int>, int> vai2;
map<int, pair<int, int> > volta2;

int ptr;
int ptr2;
pair<int, pair<int, int> > p[500004];
pair<int, int> p2[500004];
pair<int, pair<int, int> > q[500004];
pair<int, int> q2[500004];
int k;

vector<int> g[500004];
vector<int> g2[500004];

int vis[500004];

int loop1, loop2;

void dfs(int u, int pai){
	vis[u] = 1;
	// printf("..%d %d\n", u, (int)g[u].size());

	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(v == pai) continue;
		// if(u == 2) printf("#$%d %d\n", v, vis[v]);
		if(vis[v] == 1) loop1 = true;
		if(vis[v] == 0) dfs(v, u);
	}

	vis[u] = 2;
}

void dfs2(int u, int pai){
	vis[u] = 1;

	for(int i = 0; i < (int)g2[u].size(); i++){
		int v = g2[u][i];
		if(v == pai) continue;
		if(vis[v] == 1) loop2 = true;
		if(vis[v] == 0) dfs2(v, u);
	}

	vis[u] = 2;
}

int main(){

	scanf("%d", &k);

	for(int i = 0; i < k; i++){
		scanf("%d %d %d", &p[i].ff, &p[i].ss.ff, &p[i].ss.ss);
		scanf("%d %d %d", &q[i].ff, &q[i].ss.ff, &q[i].ss.ss);
		p2[i] = mp(p[i].ff, p[i].ss.ff);
		q2[i] = mp(q[i].ff, q[i].ss.ff);
	}

	for(int i = 0; i < k; i++){
		if(!vai.count(p[i])){
			vai[ p[i] ] = ptr;
			volta[ptr] = p[i];
			ptr++;
		}
		if(!vai.count(q[i])){
			vai[ q[i] ] = ptr;
			volta[ptr] = q[i];
			ptr++;
		}
		
		if(!vai2.count(p2[i])){
			vai2[ p2[i] ] = ptr2;
			volta2[ptr2] = p2[i];
			ptr2++;
		}
		if(!vai2.count(q2[i])){
			vai2[ q2[i] ] = ptr2;
			volta2[ptr2] = q2[i];
			ptr2++;
		}
		
	}

	for(int i = 0; i < k; i++){
		int u = vai[ p[i] ], v = vai[ q[i] ];
		g[u].push_back(v);
		g[v].push_back(u);
		// printf("%d %d\n", u, v);
		int u2 = vai2[ p2[i] ], v2 = vai2[ q2[i] ];


		if(u2 == v2) continue;
		g2[u2].push_back(v2);
		g2[v2].push_back(u2);
	}

	memset(vis, 0, sizeof vis);

	for(int i = 0; i < ptr; i++)
		if(!vis[i])
			dfs(i, i);

	memset(vis, 0, sizeof vis);

	for(int i = 0; i < ptr2; i++)
		if(!vis[i])
			dfs2(i, i);

	if(loop1) printf("True closed chains\n");
	else printf("No true closed chains\n");

	if(loop2) printf("Floor closed chains\n");
	else printf("No floor closed chains\n");





	return 0;
}