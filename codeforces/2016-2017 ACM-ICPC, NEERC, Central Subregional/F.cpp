#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define mp make_pair

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int p[1003];

vector<vector<int> > g[1003], rev[1003];

pair<int, pair<int, char> > v[1000006];

int f(int x){
	return x == p[x] ? x : p[x] = f(p[x]);
}

int in[1003];
int out[1003];

int color[1003];
int cnt[1003];

int main(){
	// file();

	int n, m;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++){
		scanf("%d %c %d", &v[i].ff, &v[i].ss.ss, &v[i].ss.ff);
		if(v[i].ss.ss == '>'){
			v[i].ss.ss = '<';
			swap(v[i].ff, v[i].ss.ff);
		}
	}
	for(int i = 1; i <= n; i++)
		p[i] = i;
	
	for(int i = 0; i < m; i++){
		if(v[i].ss.ss == '='){
			int a = v[i].ff, b = v[i].ss.ff;
			p[f(a)] = f(b);
		}
	}

	for(int i = 0; i < m; i++){
		if(v[i].ss.ss == '<'){
			int a = v[i].ff, b = v[i].ss.ff;

			g[f(a)].push_back(f(b));
			in[ f(b) ]++;

			rev[f(b)].push_back(f(a));
			out[ f(a) ]++;
		}
	}

	for(int i = 1; i <= n; i++){
		if(f(i) != i) continue;
		if(in[i]) continue;

		queue<int> q;
		q.push(i);
		color[i] = 1;
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int i = 0; i < (int)g[u].size(); i++){
				int v = g[u][i];
				if(color[u] + 1 > color[v]){
					color[v] = color[u]+1;
					q.push(v);
				}
			}
		}

	}

	for(int i = 1; i <= n; i++){
		if(f(i) != i) continue;
		if(out[i]) continue;

		queue<int> q;
		q.push(i);
		cnt[i] = 3;
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int i = 0; i < (int)rev[u].size(); i++){
				int v = rev[u][i];
				if(cnt[v] == 0 || cnt[u] - 1 < cnt[v]){
					cnt[v] = cnt[u]-1;
					q.push(v);
				}
			}
		}
	}

	char *s = "?BRW";
	for(int i = 1; i <= n; i++){
		if(color[f(i)] == cnt[f(i)])
			printf("%c", s[ color[ f(i) ] ]);
		else printf("?");
	}
	printf("\n");

	return 0;
}
