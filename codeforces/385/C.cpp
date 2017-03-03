#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;
int n, m, k, c[1003], vis[1003];

vector<int> g[1003];

pair<int, pair<int, bool> > dfs(int u){
	pair<int, pair<int, bool> > ret = mp(1, mp((int)g[u].size(), (bool)c[u]));
	vis[u] = 1;

	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(vis[v]) continue;
		pair<int, pair<int, bool> > tmp = dfs(v);
		ret.ff += tmp.ff;
		ret.ss.ff += tmp.ss.ff;
		ret.ss.ss |= tmp.ss.ss;
	}
	return ret;
}

int main(){

	scanf("%d %d %d", &n, &m, &k);

	int x;
	for(int i = 0; i < k; i++){
		scanf("%d", &x); x--;
		c[x] = 1;
	}

	int u, v;
	for(int i = 0; i < m; i++){
		scanf("%d %d", &u, &v); u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	long long ans = 0;

	pair<int, int> extra = mp(0, 0); // (vertex, edges)
	vector< pair<int, int> > special;
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			pair<int, pair<int, bool> > tmp = dfs(i);
			if(tmp.ss.ss){
				int n = tmp.ff;
				int e = tmp.ss.ff/2;
				ans += n*(n-1)/2 - e;

				special.push_back(mp(n, n*(n-1)/2));
			}
			else{
				extra.ff += tmp.ff;
				extra.ss += tmp.ss.ff/2;
			}

		}
	}

	int tmp = 0;

	for(int i = 0; i < (int)special.size(); i++){
		int n = special[i].ff + extra.ff;
		int e = special[i].ss + extra.ss;

		tmp = max(tmp, n*(n-1)/2 - e);
	}

	ans += tmp;

	printf("%lld\n", ans);

	return 0;
}