#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int vis[1003][1003][3][7];

char mat[1003][1003];

int n, m;

int dx[] = {0, 0,-1, 1};
int dy[] = {1,-1, 0, 0};

bool dfs(int x, int y, int turn, int dir){
	vis[x][y][turn][dir] = 1;
	if(mat[x][y] == 'T') return true;

	for(int i = 0; i < 4; i++){
		int xx = x + dx[i], yy = y + dy[i];
		if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
		if(mat[xx][yy] == '*') continue;

		int ndir = (dx[i]+1) + 2*(dx[i]+1);
		int nturn = turn + (ndir != dir && dir);
		
		if(nturn > 2 || vis[xx][yy][nturn][ndir]) continue;

		if(dfs(xx, yy, nturn, ndir))
			return true;
	}
	return false;
}

int main(){

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		scanf(" %s", mat[i]);

	int x, y;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j] == 'S'){
				x = i;
				y = j;
			}
		}
	}

	printf("%s\n", dfs(x, y, 0, 0) ? "YES" : "NO");
	



	return 0;
}