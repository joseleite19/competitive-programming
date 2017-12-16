#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, v[100005];

pair<int, int> tree[100005];

int cnt(int u){
	int ans = 1;
	if(tree[u].ff != -1) ans += cnt(tree[u].ff);
	if(tree[u].ss != -1) ans += cnt(tree[u].ss);
	return ans;
}

map<int, bool> vis;

void solve(int u, int mx, int mn){

	if(mn < v[u] && v[u] < mx) vis[ v[u] ] = true;

	if(tree[u].ff != -1) solve(tree[u].ff, min(mx, v[u]), mn);
	if(tree[u].ss != -1) solve(tree[u].ss, mx, max(mn, v[u]));
}

int main(){

	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		scanf("%d %d %d", v+i, &tree[i].ff, &tree[i].ss);

	int root = 0;
	{
		vector<int> tmp(n+1, 0);
		for(int i = 1; i <= n; i++){
			if(tree[i].ff != -1) tmp[ tree[i].ff ] = 1;
			if(tree[i].ss != -1) tmp[ tree[i].ss ] = 1;
		}
		for(int i = 1; i <= n; i++)
			if(!tmp[i])
				root = i;
	}

	solve(root, 2000000000, -1000000000);

	int ans = 0;

	for(int i = 1; i <= n; i++)
		if(!vis[ v[i] ])
			ans++;

	printf("%d\n", ans);

	return 0;
}