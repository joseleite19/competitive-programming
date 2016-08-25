#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("lucky.in", "r", stdin);
	freopen("lucky.out", "w", stdout);
}

int main(){
	file();

	int r, c, mat[105][105];

	scanf("%d %d", &r, &c);

	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			scanf("%d", &mat[i][j]);

	int ans = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){

			int x, y;
			bool win = true;
			for(int x = i+1; x < r; x++)
				if(mat[x][j] >= mat[i][j])
					win = false;
			if(win) ans++;

			win = true;
			for(int x = i-1; x >= 0; x--)
				if(mat[x][j] >= mat[i][j])
					win = false;
			if(win) ans++;

			win = true;
			for(int x = j+1; x < c; x++)
				if(mat[i][x] >= mat[i][j])
					win = false;
			if(win) ans++;

			win = true;
			for(int x = j-1; x >= 0; x--)
				if(mat[i][x] >= mat[i][j])
					win = false;
			if(win) ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}