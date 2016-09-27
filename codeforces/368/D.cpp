#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int q, n, m, ans[100005], total;

bool mat[1005][1005];

struct Query{
	int t, i, j, id;
	Query(int t = 0, int i = 0, int j = 0, int id = 0) : t(t), i(i), j(j), id(id) {}
};

Query query[100005];

vector<vector<int> > g;

void dfs(int u){
	int old, oldtot;

	oldtot = total;
	if(query[u].t == 1){
		old = mat[ query[u].i ][ query[u].j ];
		if(old == 0) total++;
		mat[ query[u].i ][ query[u].j ] = 1;
	}
	else if(query[u].t == 2){
		old = mat[ query[u].i ][ query[u].j ];
		if(old == 1) total--;
		mat[ query[u].i ][ query[u].j ] = 0;
	}
	else if(query[u].t == 3){
		for(int j = 1; j <= m; j++){
			if(mat[ query[u].i ][j]) total--;
			else total++;

			mat[ query[u].i ][j] ^= 1;
		}
	}

	ans[ query[u].id-1 ] = total;

	for(int i = 0; i < g[u].size(); i++)
		dfs(g[u][i]);

	if(query[u].t == 1) mat[ query[u].i ][ query[u].j ] = old;
	else if(query[u].t == 2) mat[ query[u].i ][ query[u].j ] = old;
	else if(query[u].t == 3)
		for(int j = 1; j <= m; j++)
			mat[ query[u].i ][j] ^= 1;

	total = oldtot;
}

int main(){
	scanf("%d %d %d", &n, &m, &q);

	g.assign(q+1, vector<int>());

	int a, b, c;
	for(int i = 1; i <= q; i++){
		scanf("%d %d", &a, &b);
		if(a < 3) scanf("%d", &c);

		query[i] = Query(a, b, c, i);
		if(a == 4) g[b].push_back(i);
		else g[i-1].push_back(i);
	}

	dfs(0);

	for(int i = 0; i < q; i++)
		printf("%d\n", ans[i]);

	return 0;
}