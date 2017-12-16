#include <bits/stdc++.h>

#define forn(i, n) for(ll i = 0; i < int(n); i++)
#define fore(i, a, b) for(ll i = int(a); i <= int(b); i++)
#define ff first
#define ss second

#define ll long long

using namespace std;

const int N = 300005;

vector<int> g[N], g2[N];
vector<pair<int, int> > t[N];

char ans1[N], ans2[N];

int vis[N], pass;

int dfs(int u){
	vis[u] = pass;
	
	int ans = 1;
	for(int v : g[u]) if(vis[v] != pass){
		ans += dfs(v);
	}
	for(auto v : t[u]) if(vis[v.ff] != pass){
		int id = v.ss;
		if(id < 0){
			if(!ans1[-id]){
				ans1[-id] = '-';
				ans += dfs(v.ff);
			}
		}
		else if(!ans1[id]){
			ans1[id] = '+';
			ans += dfs(v.ff);
		}
	}
	return ans;
}
int dfs2(int u){
	vis[u] = pass;
	
	int ans = 1;
	for(int v : g[u]) if(vis[v] != pass){
		ans += dfs2(v);
	}
	for(auto v : t[u]) if(vis[v.ff] != pass){
		int id = v.ss;
		if(id < 0){
			if(!ans2[-id]){
				ans2[-id] = '+';
			}
		}
		else if(!ans2[id]){
			ans2[id] = '-';
		}
	}
	return ans;
}

int main(){
	int n, m, s;

	scanf("%d %d %d", &n, &m, &s);

	int c, a, b;
	int id = 1;
	forn(i, m){
		scanf("%d %d %d", &c, &a, &b);

		if(c == 1) g[a].push_back(b), g2[a].push_back(b);
		else{
			t[a].emplace_back(b, id);
			t[b].emplace_back(a, -id);
			id++;
		}
	}
	pass++;
	printf("%d\n", dfs(s));
	fore(i, 1, id-1){
		if(!ans1[i]) ans1[i] = '+';
		printf("%c", ans1[i]);
	}
	printf("\n");

	pass++;

	printf("%d\n", dfs2(s));
	fore(i, 1, id-1){
		if(!ans2[i]) ans2[i] = '+';
		printf("%c", ans2[i]);
	}
	printf("\n");



	return 0;
}

