#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int mat[505][505];
int vis[505][505][8][32];
// 0 - up 
// 1 - down 
// 2 - left 
// 3 - rigth 
// 4 - up/right 
// 5 - up/left
// 6 - down/right
// 7 - down/left


// 0 -> 4, 5
// 1 -> 6, 7
// 2 -> 5, 7
// 3 -> 4, 6
// 4 -> 0, 3
// 5 -> 0, 2
// 6 -> 1, 3
// 7 -> 1, 2

int dx[] = {-1, 1, 0, 0,-1,-1, 1, 1};
int dy[] = { 0, 0,-1, 1, 1,-1, 1,-1};

int n, t[32];

void dfs(int i, int j, int how, int it){
	if(it == n) return;
	if(vis[i][j][how][ t[it] ]) return;
	vis[i][j][how][ t[it] ] = 1;

	mat[i][j] = 1;
	int x = i, y = j;

	for(int i = 0; i < t[it]-1; i++){
		x += dx[how];
		y += dy[how];
		mat[x][y] = 1;
	}
	if(how == 0){
		dfs(x+dx[4], y+dy[4], 4, it+1);
		dfs(x+dx[5], y+dy[5], 5, it+1);
	}
	else if(how == 1){
		dfs(x+dx[6], y+dy[6], 6, it+1);
		dfs(x+dx[7], y+dy[7], 7, it+1);
	}
	else if(how == 2){
		dfs(x+dx[5], y+dy[5], 5, it+1);
		dfs(x+dx[7], y+dy[7], 7, it+1);
	}
	else if(how == 3){
		dfs(x+dx[4], y+dy[4], 4, it+1);
		dfs(x+dx[6], y+dy[6], 6, it+1);
	}
	else if(how == 4){
		dfs(x+dx[0], y+dy[0], 0, it+1);
		dfs(x+dx[3], y+dy[3], 3, it+1);
	}
	else if(how == 5){
		dfs(x+dx[0], y+dy[0], 0, it+1);
		dfs(x+dx[2], y+dy[2], 2, it+1);
	}
	else if(how == 6){
		dfs(x+dx[1], y+dy[1], 1, it+1);
		dfs(x+dx[3], y+dy[3], 3, it+1);
	}
	else if(how == 7){
		dfs(x+dx[1], y+dy[1], 1, it+1);
		dfs(x+dx[2], y+dy[2], 2, it+1);
	}
}

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", t+i);

	dfs(250, 250, 0, 0);

	int ans = 0;

	for(int i = 0; i < 505; i++)
		for(int j = 0; j < 505; j++)
			ans += mat[i][j];

	printf("%d\n", ans);

	return 0;
}