#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int p[1000006];
int pai[1000006];

set<int> g[1000006];

map<pair<int, int>, int> apagado;

int flag;
int qd[300005], qe[300005],pd,pe,ppd,ppe;

int ptr = 1;
void bfs(int u, int v, int bb = 0){


	vector<int> v1, v2;

	qd[0] = u;
	qe[0] = v;
	pd = pe = 1;
	ppd = ppe = 0;
	pai[u] = u;
	pai[v] = v;
	while(ppd < pd && ppe < pe){
		// int ddd = qd.front().ff;
		
		// while(!qd.empty() && qd.front().ff == ddd){
			int aa = qd[ppd]; ppd++;
			v1.push_back(aa);

			for(set<int>::iterator it = g[aa].begin(); it != g[aa].end(); it++){
				int w = *it;
				if(w == pai[aa]) continue;
				pai[w] = aa;
				qd[pd] = w;
				pd++;
			}
		// }

//		ddd = qe.front().ff;
		
		// while(!qe.empty() && qe.front().ff == ddd){
			aa = qe[ppe]; ppe++;
			v2.push_back(aa);

			for(set<int>::iterator it = g[aa].begin(); it != g[aa].end(); it++){
				int w = *it;
				if(w == pai[aa]) continue;
				pai[w] = aa;
				qe[pe];
				pe++;
			}
		// }
	}

	if(ppd >= pd){
		flag = 1;
		int color = bb ? ptr++ : p[v];
		for(int i = 0; i < (int)v1.size(); i++){
			p[ v1[i] ] = color;
		}
		return;
	}
	flag = 2;
	int color = bb ? ptr++ : p[u];
	for(int i = 0; i < (int)v2.size(); i++){
		p[ v2[i] ] = color;
	}
}


int main(){

	int n;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		p[i] = ptr++;

	char c = 'a';
	int u, v;

	while(c != 'E'){
		scanf(" %c", &c);

		if(c == 'C'){
			scanf("%d %d", &u, &v); u--; v--;

			bfs(u, v);

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