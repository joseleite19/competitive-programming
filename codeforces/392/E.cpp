#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000000000000

using namespace std;

int n;
vector<pair<int, pair<int, int> > > g[200005];

long long cnt[200005];

void count(int u, int p){

	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i].ff;
		if(v != p){
			count(v, u);
			cnt[u] += g[u][i].ss.ff + cnt[v];
		}
	}
}

bool impossible;

long long take;

void solve(int u, int p){

	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i].ff;
		int w = g[u][i].ss.ff;
		int q = g[u][i].ss.ss;
		if(v == p) continue;

		if(q < cnt[v]) take += cnt[v] - q;

		solve(v, u);

		long long k = min(w-1LL, q-cnt[v]);
		if(k < 0) impossible = true;
		k = min(k, take);
		if(k < 0) impossible = true;

		take -= k;

		g[u][i].ss.ff -= k;
		g[u][i].ss.ss -= k;
	}
	cnt[u] = 0;
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i].ff;
		if(v != p){
			
			cnt[u] += g[u][i].ss.ff + cnt[v];
		}
	}
	// printf("%d.. %lld\n", u+1, take);
	// for(int i = 0; i < n; i++)
	// 	printf("%d ", cnt[i]);
	// printf("\n");
}


map<pair<int, int>, int> volta;
vector<
	pair<int, 
		pair<int,
			pair<int,
				pair<int,
					int
				>
			>
		>
	>
> vv;
void print(int u, int p){
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i].ff;
		int w = g[u][i].ss.ff;
		int q = g[u][i].ss.ss;
		if(v == p) continue;
		print(v, u);
		if(volta.count(mp(u, v))){
			vv.push_back(mp(volta[mp(u, v)], mp(u+1, mp(v+1, mp(w, q)))));
		}
		else{
			vv.push_back(mp(volta[mp(v, u)], mp(v+1, mp(u+1, mp(w, q)))));
		}
		// printf("%d %d %d %d\n", u+1, v+1, w, q);
	}
}

int main(){

	scanf("%d", &n);


	int u, v, w, p;

	for(int i = 0; i < n-1; i++){
		scanf("%d %d %d %d", &u, &v, &w, &p); u--; v--;
		g[u].push_back(mp(v, mp(w, p)));
		g[v].push_back(mp(u, mp(w, p)));
		volta[ mp(u, v) ] = i;
	}

	count(0, 0);

	solve(0, 0);

	print(0, 0);

	sort(vv.begin(), vv.end());

	if(impossible){
		printf("%d\n", -1);

		return 0;
	}

	printf("%d\n", n);
	for(int i = 0; i < (int)vv.size(); i++){
		printf("%d %d %d %d\n", vv[i].ss.ff, vv[i].ss.ss.ff, vv[i].ss.ss.ss.ff, vv[i].ss.ss.ss.ss);
	}

	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < (int)g[i].size(); j++){
	// 		printf("%d %d %d %d\n", i+1, g[i][j].ff+1, g[i][j].ss.ff, g[i][j].ss.ss);
	// 	}
	// }




	return 0;
}