#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, m;
vector<int> g[300005];
vector<int> h[300005];

int color[300005];

set<int> s;

void dfs(int u, int p){
    for(int uu : g[u]) s.erase(color[uu]);


    for(int uu : g[u]){
        if(!color[uu]){
            color[uu] = *s.begin();
            s.erase(s.begin());
        }
    }
    for(int uu : g[u]) s.insert(color[uu]);

    for(int v : h[u]){
        if(v == p) continue;
        dfs(v, u);
    }
}

int main(){
	scanf("%d %d", &n, &m);

	int ans = -1, id = 0;
	for(int i = 1; i <= n; i++){
		int sz, x;
		scanf("%d", &sz);
		while(sz--){
			scanf("%d", &x);
			g[i].push_back(x);
		}
		if(int(g[i].size()) > ans) ans = int(g[i].size()), id = i;
	}
	ans = max(ans, 1);

    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        h[u].push_back(v);
        h[v].push_back(u);
    }

    for(int i = 1; i <= ans; i++)
        s.insert(i);

    dfs(1, -1);
	for(int i = 1; i <= m; i++)
		if(!color[i])
			color[i] = 1;

	printf("%d\n", ans);

	for(int i = 1; i <= m; i++){
		printf("%d ", color[i]);
	}
	printf("\n");




	return 0;
}
