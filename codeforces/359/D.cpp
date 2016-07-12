#include <bits/stdc++.h>
#define MAXN 300005

using namespace std;

int n, q, p[MAXN], sublen[MAXN], resp[MAXN];

vector<vector<int> > g;

pair<int,int> cntlen(int u){
	int ans = 0;
	pair<int,int> grt = {-1, -1};
	for(int v : g[u]){
		pair<int,int> tmp =  cntlen(v);
		ans += tmp.first;
		grt = max(grt, tmp);
	}
	sublen[u] = ans + 1;

	if(2*grt.first > sublen[u]){
		if(2 * sublen[ grt.second ] > sublen[u])
			resp[u] = grt.second;
		else{
			while(2 * sublen[ grt.second ] < sublen[u])
				grt.second = p[grt.second];
			resp[u] = grt.second;
		}
	}
	else resp[u] = u;

	return {sublen[u], resp[u]};
}

int main(){

	scanf("%d %d", &n, &q);
	g.assign(n+1, vector<int>());
	int x;
	for(int i = 2; i <= n; i++){
		scanf("%d", p+i);
		g[ p[i] ].push_back(i);
	}
	cntlen(1);
	while(q--)
		scanf("%d", &x), printf("%d\n", resp[x]);
}