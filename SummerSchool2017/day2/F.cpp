#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, p[100005], r[100005], t[100005];

vector<int> g[100005];
vector<int> g2[100005];

stack<pair<int, int> > s;

int still[100005];

long long ft[100005];
long long resp[100005];

void add(int x, long long v){
	for(; x <= 100005; x += x&-x)
		ft[x] += v;
}

long long sum(int x){
	long long ans = 0;
	for(; x; x -= x&-x)
		ans += ft[x];
	return ans;
}

void add(int l, int r, long long v){
	add(l, v);
	add(r+1, -v);
}

int dfs(int u, int p){
	// printf("asd\n");

	resp[u] = sum(r[u]);

	for(int i = 0; i < (int)g[u].size(); i++){
		// s.push(mp(r[u]), u);
		int v = g[u][i];
		if(v == p) continue;
		add(r[v] + 1, 100003, t[v]);
		dfs(v, u);
		// add(r[v] + 1, 100003, -t[v]);
	}

	resp[u] = sum(r[u]) - resp[u];
}

int main(){

	scanf("%d", &n);

	int root = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d %d %d", p+i, r+i, t+i);
		if(p[i] == -1) root = i;
		else g[ p[i] ].push_back(i);
	}

	dfs(root, root);

	for(int i = 1; i <= n; i++)
		printf("%lld\n", resp[i]);




	return 0;
}