#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int p[1000006];
int sz[1000005];
int pai[1000006];

set<int> g[1000006];

int flag;

int ptr = 1;
void bfs(int u, int v, int bb = 0){

	queue<int> qd, qe;

	vector<int> v1, v2;

	qd.push(u);
	qe.push(v);
	pai[u] = u;
	pai[v] = v;
	bool first = true;
	set<int>::iterator it1;
	set<int>::iterator it2;
	int ud;
	int ue;
	while(!qd.empty() && !qe.empty()){
		if(first){
			ud = qd.front();
			ue = qe.front();
			it1 = g[ud].begin();
			it2 = g[ue].begin();
			first = 0;
			v1.push_back(ud);
			v2.push_back(ue);
		}

		if(it1 != g[ud].end()){
			int w = *it1;
			if(w != pai[ud]){
				pai[w] = ud;
				qd.push(w);
				v1.push_back(w);
			}
			it1++;
		}
		if(it1 == g[ud].end()){
			qd.pop();
			if(!qd.empty()) ud = qd.front();
		}

		if(it2 != g[ue].end()){
			int w = *it2;
			if(w != pai[ue]){
				pai[w] = ue;
				qe.push(w);
				v2.push_back(w);
			}
			it2++;
		}
		if(it2 == g[ue].end()){
			qe.pop();
			if(!qe.empty()) ue = qe.front();
		}
	}

	if(qd.empty()){
		flag = 1;
		sz[p[v]] = sz[p[v]] - v1.size();
		int color = bb ? ptr++ : p[v];
		sz[color] = v1.size();
		for(int i = 0; i < (int)v1.size(); i++){
			p[ v1[i] ] = color;
		}
		return;
	}
	sz[p[u]] = sz[p[u]] - v2.size();
	flag = 2;
	int color = bb ? ptr++ : p[u];
	sz[color] = v2.size();
	for(int i = 0; i < (int)v2.size(); i++){
		p[ v2[i] ] = color;
	}
}

void bfs2(int v, int u){

	queue<pair<int, int> > qe;

	qe.push(mp(1, v));
	pai[v] = v;
	while(!qe.empty()){
		int aa = qe.front().ss; qe.pop();
		p[aa] = p[u];

			for(set<int>::iterator it = g[aa].begin(); it != g[aa].end(); it++){
				int w = *it;
				if(w == pai[aa]) continue;
				pai[w] = aa;
				qe.push(mp(1, w));
			}
		//}
	}
}

int main(){

	int n;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		sz[i]++;
		p[i] = ptr++;
	}
	char c = 'a';
	int u, v;

	while(c != 'E'){
		scanf(" %c", &c);

		if(c == 'C'){
			scanf("%d %d", &u, &v); u--; v--;
			if(sz[p[u]] > sz[p[v]]){
				bfs2(v,u);
				sz[p[u]] += sz[p[v]];
				sz[p[v]] = 0;
			}
			else{
				bfs2(u,v);
				sz[p[v]] += sz[p[u]];
				sz[p[u]] = 0;
			}
			//bfs(u, v);
			g[u].insert(v);
			g[v].insert(u);
		}
		if(c == 'D'){
			scanf("%d %d", &u, &v); u--; v--;
			g[u].erase(v);
			g[v].erase(u);
			bfs(u, v, 1);
		}
		if(c == 'T'){
			scanf("%d %d", &u, &v); u--; v--;
			printf("%s\n", p[u] == p[v] ? "YES" : "NO");
			fflush(stdout);
		}
	}


	return 0;
}