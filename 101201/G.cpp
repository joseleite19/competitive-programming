#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000

using namespace std;

const int N = 55;

int cnt[N][N];
char mat[N][N];

int dx[] = {0, 0,-1, 1};
int dy[] = {1,-1, 0, 0};

int n, m;

vector<pair<int, pair<long long, int> > > g[100005]; // <vx, <edge weight, id reverse edge>>

int lvl[100005], vis[100005], source, target;

size_t px[100005];

long long run(int s, long long minE){
	if(s == target) return minE;

	long long ans = 0;

	for(; px[s] < g[s].size(); px[s]++){
		auto &v = g[s][ px[s] ];
		if(lvl[v.ff] != lvl[s]+1 || !v.ss.ff) continue;
		long long tmp = run(v.ff, min(minE, v.ss.ff));
		v.ss.ff -= tmp;
		g[v.ff][v.ss.ss].ss.ff += tmp;
		ans += tmp;
		minE -= tmp;
		if(minE == 0) break;
	}
	return ans;
}

int pass;
int bfs(){

	queue<int> q;
	q.push(source);
	lvl[source] = 1;
	vis[source] = ++pass;

	while(!q.empty()){
		int u = q.front(); q.pop();
		px[u] = 0;

		for(auto v : g[u]){
			if(v.ss.ff <= 0 || vis[v.ff] == pass) continue;
			vis[v.ff] = pass;
			lvl[v.ff] = lvl[u]+1;
			q.push(v.ff);
		}
	}

	return vis[target] == pass;
}

long long flow(){

	long long ans = 0;
	while(bfs())
		ans += run(source, oo);
	return ans;
}

void addEdge(int u, int v, long long c){
	pair<int, pair<long long, int> > a, b;
	a = {u, {0, g[u].size()}};
	b = {v, {c, g[v].size()}};
	g[u].push_back(b);
	g[v].push_back(a);
}


int main(){

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf(" %s", mat[i]);

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(cnt[i][j]) continue;
            if(mat[i][j] != 'L') continue;

            queue<int> qx, qy;
            qx.push(i), qy.push(j);
            ans++;

            cnt[i][j] = 1;
            while(!qx.empty()){
                int x = qx.front(); qx.pop();
                int y = qy.front(); qy.pop();
                if(mat[x][y] != 'L') continue;
                for(int w = 0; w < 4; w++){
                    int xx = x + dx[w], yy = y + dy[w];
                    if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                    if(cnt[xx][yy]) continue;
                    cnt[xx][yy] = 1;
                    qx.push(xx), qy.push(yy);
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] == 'W')
                cnt[i][j] = 1;

    source = N*N;
    target = N*N+1;

    int tmp = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(cnt[i][j]) continue;
            tmp++;

            if((N*i+j)&1) addEdge(i*N+j, target, 1);
            else{
                addEdge(source, i*N+j, 1);
                for(int w = 0; w < 4; w++){
                    int ii = i + dx[w], jj = j + dy[w];
                    if(ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                    if(cnt[ii][jj]) continue;
                    addEdge(i*N+j, ii*N+jj, 1);
                }
            }

        }
    }

    printf("%d\n", ans + (tmp - flow()));

    return 0;
}
