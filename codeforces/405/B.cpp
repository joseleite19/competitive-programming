#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD (1000000007)
#define oo (1000000000000000000)

using namespace std;

// bitset<150005> out[150000];
// bitset<150005> tmp;

long long n, m;

vector<int> g[150005];

bool can;


long long cnt, cnt2;

int vis[150005];
int apaga[150005];

void dfs(int u){
	vis[u] = 1;
	if(apaga[u]) return;

	cnt++;
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(apaga[v]) continue;
		cnt2++;
		if(vis[v]) continue;
		dfs(v);
	}
}

int in[150005];

int main(){

	scanf("%lld %lld", &n, &m);

	for(int i = 0; i < m; i++){
		int u, v;

		scanf("%d %d", &u, &v); u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
		in[v]++;
		in[u]++;
	}

	can = 1;
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			cnt = cnt2 = 0;
			dfs(i);
			if(cnt*(cnt-1)/2 != cnt2/2) can = 0;
		}
	}


	printf("%s\n", can ? "YES" : "NO");


	return 0;
}