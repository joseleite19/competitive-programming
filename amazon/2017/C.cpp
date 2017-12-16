#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

vector<vector<int> > g;
vector<vector<int> > gt;

int tempo = 1;
vector<int> c, f, color;
void dfs(int u){
	c[u] = tempo++;

	for(int v : g[u]){
		if(c[v]) continue;
		dfs(v);
	}

	f[u] = tempo++;
}

int sz[N];

void dfst(int u, int c){
	color[u] = c;
    sz[c]++;
	for(int v : gt[u]){
		if(color[v]) continue;
		dfst(v, c);
	}
}

vector<int> dag[N];
int in[N];

int dp[N];

int ff(int u){
    if(~dp[u]) return dp[u];
    int ans = 0;

    for(int v : dag[u])
        ans = max(ans, ff(v));
    ans += sz[u];
    return dp[u] = ans;
}

int main(){

	int n, m, u, v;

	scanf("%d %d", &n, &m);
	g.assign(n+1, vector<int>());
	gt.assign(n+1, vector<int>());
	c.assign(n+1, 0);
	f.assign(n+1, 0);
	color.assign(n+1, 0);

	for(int i = 0; i < m; i++){
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		gt[v].push_back(u);
	}

	for(int i = 1; i <= n; i++)
		if(!c[i])
			dfs(i);

	vector<pair<int, int> > tmp;
	for(int i = 1; i <= n; i++)
		tmp.emplace_back(f[i], i);
	sort(tmp.begin(), tmp.end(), greater<pair<int, int> >());

	int e = 0;
	for(int i = 0; i < tmp.size(); i++){
		if(color[ tmp[i].second ]) continue;
		dfst(tmp[i].second, ++e);
	}

    for(int i = 1; i <= n; i++){
        for(int v : g[i])
            if(color[v] != color[i])
                dag[color[i]].push_back(color[v]), in[ color[v] ]++;
    }

    memset(dp, -1, sizeof dp);

    int ans = 0, qnt = 0;
    for(int i = 1; i <= e; i++)
        if(!in[i]){
            int tmp = ff(i);
            if(tmp > ans) ans = tmp, qnt = sz[i];
            else if(tmp == ans) qnt += sz[i];
        }
    printf("%d %d\n", ans, qnt);
    

	return 0;
}
