#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, maxzao, color[500005], cnt[500005], sz[500005], h[500005];
long long ans, resp[500005];

vector<int> g[500005];

vector<pair<int, int> > q[500005];

char s[500005];

int change(int u){
	return (1 << (s[u]-'a'));
}

void count_size(int u, int p = -1){
	sz[u] = 1;

	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(v == p) continue;
		h[v] = h[u]+1;
		count_size(v, u), sz[u] += sz[v];
	}
}

void add(int u, int p, int big = -1){

	cnt[ h[u] ] ^= change(u);

	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(v == p || v == big) continue;
		add(v, u);
	}
}

void dfs(int u, int p, int keep){

	int big = -1, mmx = -1;

	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(v == p || sz[v] <= mmx) continue;
		mmx = sz[v], big = v;
	}

	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(v == p || v == big) continue;
		dfs(v, u, 0);
	}

	if(big != -1) dfs(big, u, 1);

	add(u, p, big);

	// resp[u] = ans;

	for(int i = 0; i < (int)q[u].size(); i++){
		int he = q[u][i].ff, id = q[u][i].ss;
		resp[id] = __builtin_popcount(cnt[he]) <= 1 ? 1 : 0;
	}

	if(!keep) add(u, p), maxzao = ans = 0;
}

int main(){
	int m;

	scanf("%d %d", &n, &m);

	for(int i = 1; i < n; i++){
		int v;
		scanf("%d", &v); v--;
		g[i].push_back(v);
		g[v].push_back(i);
	}

	scanf(" %s", s);

	for(int i = 0; i < m; i++){
		int v, h;
		scanf("%d %d", &v, &h);

		q[v-1].push_back(mp(h, i));
	}

	h[0] = 1;
	count_size(0);

	dfs(0, 0, 0);

	for(int i = 0; i < m; i++)
		printf("%s\n", resp[i] ? "Yes" : "No");

	return 0;
}