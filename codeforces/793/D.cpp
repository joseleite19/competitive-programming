#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000

using namespace std;

vector<pair<int, int> > g[100];

int dp[82][82][82][82];

int n;

int f(int k, int i, int l, int r){
	if(k == 0){
		return 0;
	}
	int &ans = dp[k][i][l][r];
	if(~ans) return ans;
	ans = oo;
	for(pair<int, int> p : g[i]){
		if(l < p.ff && p.ff < r){
			if(p.ff > i)
				ans = min(ans, p.ss + f(k-1, p.ff, i, r));
			else
				ans = min(ans, p.ss + f(k-1, p.ff, l, i));
		}
	}

	return ans;
}

int main(){
	
	int k, m;
	scanf("%d %d %d", &n, &k, &m);

	for(int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back(mp(v, w));
		// g[v].push_back(mp(u, w));
	}

	memset(dp, -1, sizeof dp);
	int ans = oo;
	for(int i = 1; i <= n; i++)
		ans = min(ans, f(k-1, i, 0, n+1));

	if(ans == oo) ans = -1;
	printf("%d\n", ans);


	return 0;
}