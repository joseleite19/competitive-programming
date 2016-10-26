#include <bits/stdc++.h>

#define ss second
#define ff first
#define mp make_pair

using namespace std;

char mat[100][100];
bool vis[100][100];
int n, m, k;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dfs(int x, int y, int cnt = 0){
	if(vis[x][y]) return 0;
	vis[x][y] = 1;
	if(cnt) mat[x][y] = '*';
	int ret = 1;

	for(int i = 0; i < 4; i++){
		int xx = x+dx[i];
		int yy = y+dy[i];
		if(xx < 0 || xx > 100 || yy < 0 || yy > 100) continue;
		if(mat[xx][yy] != '*') ret += dfs(xx, yy, cnt);
	}
	return ret;
}

int main(){
	scanf("%d %d %d", &n, &m, &k);

	memset(mat, '.', sizeof mat);
	for(int i = 1; i <= n; i++){
		scanf(" %s", mat[i]+1);
	}
	dfs(0,0);
	int mm, ii = 0, jj = 0;
	set< pair<int, pair<int, int> > > s;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(mat[i][j] == '.' && !vis[i][j]){
				s.insert( mp(dfs(i, j), mp(i, j)) );
			}
		}
	}

	memset(vis, 0, sizeof vis);
	dfs(0,0);

	int ans = 0;
	while(s.size() > k){
		ans += dfs(s.begin()->ss.ff, s.begin()->ss.ss, 1);
		s.erase(s.begin());
	}
	printf("%d\n", ans);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			printf("%c", mat[i][j]);
		printf("\n");
	}


	return 0;
}