#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

int cnt[100005], st[100005], color[100005];
vector<int> G[100005];
bool big[100005];
ll ans[100005];

void treesize(int v, int p){
	st[v] = 1;
	for(int x : G[v])
		if(x != p){
			treesize(x,v);
			st[v] += st[x];
		}
}

pair<ll, int> best;

void add(int v, int p, int qtd, pair<ll,int> &b){
	cnt[color[v]] += qtd;
	if(qtd == 1){
		if(cnt[color[v]] == best.ss) best.ff += color[v];
		else if(cnt[color[v]] > best.ss) best = mp(color[v],cnt[color[v]]); 
	}

	for(int x : G[v]){
		if(x != p && big[x] == 0)
			add(x,v,qtd,best);
	}
}

void dfs(int v, int p, bool keep){
	int mx = -1, bigChild = -1;

	for(int x : G[v])
		if(x != p && st[x] > mx) mx = st[x], bigChild = x;

	for(int x : G[v])
		if(x != p && x != bigChild) dfs(x,v,0);

	if(bigChild != -1){
		dfs(bigChild, v, 1);
		big[bigChild] = 1;
	}

	add(v,p,1,best);

	ans[v] = best.ff;

	if(bigChild != -1)
        big[bigChild] = 0;

    if(keep == 0){
        add(v, p, -1, best);
        best = mp(0,0);
    }

    // return best;
}

int main(){
	int n,a,b;

	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		scanf("%d", &color[i]);

	for(int i = 1; i < n; i++){
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	treesize(1,1);
	dfs(1,1,1);

	for(int i = 1; i <= n; i++)
		printf("%lld ", ans[i]);
	printf("\n");

	return 0;
}