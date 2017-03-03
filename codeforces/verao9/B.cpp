#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define oo 1000000

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

pair<int, int> mat[150][150];

int start = 26000, target = 26001;

int w[20002][20002];

vector<int> g[20002];

int p[20002];

int back(int u, int me){
	if(u == start) return me;
	int f = back(p[u], min(me, w[ p[u] ][u]));
	w[ p[u] ][u] -= f;
	w[u][ p[u] ] += f;
	return f;
}

int maxflow(){
	int mf = 0;

	while(1){
		queue<int> q;

		q.push(start);
		memset(p, -1, sizeof p);

		p[start] = start;

		while(!q.empty()){
			int u = q.front(); q.pop();
			if(u == target) break;
			for(int i = 0; i < (int)g[u].size(); i++){
				int v = g[u][i];
				if(p[v] == -1 && w[u][v] > 0){
					p[v] = u;
					q.push(v);
				}
			}
		}

		if(p[target] == -1) break;

		int f = back(target, oo);
		if(f == 0) break;
		mf += f;
	}

	return mf;
}

pair<int, int> cima[16000]; 
pair<int, int> lado[16000]; 

int main(){
	// file();
	int n, m;

	scanf("%d %d", &n, &m);
	char s[10];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %s", s);
			if(s[2] == '.') mat[i][j].ff = mat[i][j].ss = -2;
			
			if(s[0] == 'X') mat[i][j].ff = -1;
			else sscanf(s, "%d", &mat[i][j].ff);
			
			if(s[3] == 'X') mat[i][j].ss = -1;
			else sscanf(s+3, "%d", &mat[i][j].ss);
		}
	}

	int ptr = 1;
	map<pair<int, int>, int> vai;
	map<int, pair<int, int> > volta;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			vai[ mp(i, j) ] = ptr;
			volta[ptr] = mp(i, j);
			ptr++;
		}
	}

	memset(cima, -1, sizeof cima);
	memset(lado, -1, sizeof lado);

	int tot = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j].ff > 0){

				int k;
				for(k = i+1; k < n; k++)
					if(mat[k][j].ff != -2)
						break;
				
				mat[i][j].ff -= k-1-i;
				tot += mat[i][j].ff;

				w[start][ vai[mp(i, j)] ] = mat[i][j].ff;
				g[start].push_back(vai[mp(i, j)]);
				
				for(int q = i+1; q < k; q++){
					cima[ vai[mp(q, j)] ] = mp(i, j);
				}

			}
			if(mat[i][j].ss > 0){

				int k;
				for(k = j+1; k < m; k++)
					if(mat[i][k].ff != -2)
						break;

				mat[i][j].ss -= k-1-j;

				tot += mat[i][j].ss;

				w[ vai[mp(i, j)]+10002 ][ target ] = mat[i][j].ss;
				g[ vai[mp(i, j)]+10002 ].push_back(target);
				for(int q = j+1; q < k; q++){
					lado[ vai[mp(i, q)] ] = mp(i, j);
				}

			}
		}
	}

	for(int i = 1; i < ptr; i++){
		if(cima[i].ff == -1) continue;

		w[ vai[ cima[i] ] ][ vai[ lado[i] ]+10002 ] = 8;
		w[ vai[ lado[i] ]+10002 ][ vai[ cima[i] ] ] = 0;

		g[ vai[ cima[i] ] ].push_back(vai[ lado[i] ]+10002);
		g[ vai[ lado[i] ]+10002 ].push_back(vai[ cima[i] ]);
	}

	maxflow();

	for(int i = 0; i < n; i++){
		if(mat[i][0].ff != -2) printf("_");
		else printf("%d", w[ vai[ lado[ vai[mp(i, 0)] ] ]+10002 ][ vai[ cima[ vai[mp(i, 0)] ] ] ] + 1);
		
		for(int j = 1; j < m; j++){
			if(mat[i][j].ff != -2){
				printf(" _");
				continue;
			}
			printf(" %d", w[ vai[ lado[ vai[mp(i, j)] ] ]+10002 ][ vai[ cima[ vai[mp(i, j)] ] ] ] + 1);
		}
		printf("\n");
	}

	return 0;
}