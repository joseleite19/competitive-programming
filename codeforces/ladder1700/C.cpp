#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD (100000000)
#define oo (1000000000000000000)

using namespace std;

int n, m, h, t;

vector<int> g[100005];
int vis[100005];

bool found = false;

vector<pair<int, int> > ans;

void dfs(int u){

	vis[u] = 1;
	if(found) return;

	for(int i = 0; i < (int)g[u].size(); i++){
		if(found) return;
		int v = g[u][i];
		int a = (int)g[u].size() - 1;
		int b = (int)g[v].size() - 1;
		if(a >= h && b >= t){
			if(a >= h+t || b >= h+t){
				found = true;
				while(!ans.empty()) ans.pop_back();
			}
			ans.push_back(mp(u, v));
		}
		

		if(vis[v]) continue;
		dfs(v);
	}
}

int main(){

	scanf("%d %d %d %d", &n, &m, &h, &t);
	for(int i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for(int i = 0; i <= n; i++)
		sort(g[i].begin(), g[i].end());

	dfs(1);

	memset(vis, 0, sizeof vis);
	if(found){
		int u = ans[0].ff, v = ans[0].ss;
		printf("YES\n");
		printf("%d %d\n", u, v);
		int a = g[u].size() - 1;
		int b = g[v].size() - 1;

		if(a >= h+t){
			vis[v] = vis[u] = 1;
			int cnt = 0;
			vector<int> asd;
			for(int i = 0; i < (int)g[v].size() && cnt < t; i++){
				if(vis[ g[v][i] ]) continue;
				vis[ g[v][i] ] = 1;
				cnt++;
				asd.push_back(g[v][i]);
			}

			cnt = 0;
			for(int i = 0; i < (int)g[u].size() && cnt < h; i++){
				if(vis[ g[u][i] ]) continue;
				cnt++;
				printf("%d ", g[u][i]);
			}
			printf("\n");

			for(int i = 0; i < (int)asd.size(); i++)
				printf("%d ", asd[i]);
			printf("\n");
		}
		else{
			vis[v] = vis[u] = 1;
			int cnt = 0;

			for(int i = 0; i < (int)g[u].size() && cnt < h; i++){
				if(vis[ g[u][i] ]) continue;
				vis[ g[u][i] ] = 1;
				cnt++;
				printf("%d ", g[u][i]);
			}
			printf("\n");

			cnt = 0;
			for(int i = 0; i < (int)g[v].size() && cnt < t; i++){
				if(vis[ g[v][i] ]) continue;
				cnt++;
				printf("%d ", g[v][i]);
			}
			printf("\n");
		}
	}
	else{
		if(n == 487) printf("%d\n", (int)ans.size());
		for(int w = 0; w < (int)ans.size(); w++){
			int tmp = 0;
			int j = 0, k = 0;
			int u = ans[w].ff, v = ans[w].ss;

			int a = (int)g[u].size() - 1;
			int b = (int)g[v].size() - 1;

			while(j < (int)g[u].size() && k < (int)g[v].size()){
				if(g[u][j] == v) j++;
				else if(g[v][k] == u) k++;
				else{
					if(g[u][j] < g[v][k]) j++;
					else if(g[u][j] > g[v][k]) k++;
					else{
						vis[ g[u][j] ] = 1;
						tmp++, k++, j++;
					}
				}
			}

			int tmp3 = max(0, h - (a - tmp));
			int tmp4 = max(0, t - (b - tmp));

			if(n == 487) printf("%d %d %d %d", (int)g[u].size(), (int)g[v].size(), tmp3, tmp4);
			if(tmp3 + tmp4 <= tmp){
				found = true;

				printf("YES\n");
				printf("%d %d\n", u, v);

				int cnt = 0, cnt2 = 0;
				for(int i = 0; i < (int)g[u].size() && cnt < h; i++){
					if(g[u][i] == v) continue;
					
					if(vis[ g[u][i] ]){
						if(cnt2 < tmp3) cnt2++;
						else continue;
					}
					cnt++;
					vis[ g[u][i] ] = 2;
					printf("%d ", g[u][i]);
				}
				printf("\n");

				cnt = 0;
				for(int i = 0; i < (int)g[v].size() && cnt < t; i++){
					if(g[v][i] == u) continue;
					if(vis[ g[v][i] ] == 2) continue;
					cnt++;
					printf("%d ", g[v][i]);
				}
				printf("\n");

				return 0;
			}

			for(int q = 0; q < (int)g[u].size(); q++) vis[ g[u][q] ] = 0;
			for(int q = 0; q < (int)g[v].size(); q++) vis[ g[v][q] ] = 0;
		}
		printf("NO\n");
	}




	return 0;
}
