#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define mp make_pair

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int n, m;
pair<int, int> t[102], a[102];

vector<int> g[204];

int match[204];

char s[204][10];

int vis[204];

int mat[204][204];

bool dfs(int u){

	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(vis[v]) continue;
		vis[v] = 1;
		
		if(match[v] == -1 || dfs(match[v])){
			match[v] = u;
			match[u] = v;
			return true;
		}
	}

	return false;
}


int main(){
	// file();

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		scanf(" %s", s[i]);
		int q = s[i][0]-'0' + s[i][1]-'0' + s[i][2]-'0';
		int w = s[i][3]-'0' + s[i][4]-'0' + s[i][5]-'0';
		t[i] = mp(q, w);
	}
	for(int i = 0; i < m; i++){
		scanf(" %s", s[100+i]);
		int q = s[100+i][0]-'0' + s[100+i][1]-'0' + s[100+i][2]-'0';
		int w = s[100+i][3]-'0' + s[100+i][4]-'0' + s[100+i][5]-'0';
		a[i] = mp(q, w);
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(t[i].ff == a[j].ss || t[i].ss == a[j].ff){
				g[i].push_back(100+j);
			}
		}
	}

	memset(match, -1, sizeof match);
	int ans = 0;
	for(int i = 0; i < n; i++){
		memset(vis, 0, sizeof vis);
		if(dfs(i)){
			ans++;
		}
	}

	printf("%d\n", ans);
	for(int i = 0; i < n; i++){
		if(match[i] == -1) continue;

		if(t[i].ff == a[ match[i]-100 ].ss)
			printf("AT %s %s\n", s[i], s[ match[i] ]);
		else
			printf("TA %s %s\n", s[ match[i] ], s[i]);

	}




	return 0;
}
