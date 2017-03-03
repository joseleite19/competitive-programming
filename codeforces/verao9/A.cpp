#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
int n, m;
int mat[200][200];
int vis[200][200];
char s[1000];

int main(){

	scanf("%d %d", &n, &m);

	char c;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf(" %c", &c);
			mat[i][j] = c - '0';
		}
	}

	scanf(" %s", s);

	int x = 1, y = 1, dir = 0; // 0 = -> | 1 = <- | 2 = /\ | 3 = V

	long long ans = 0;

	for(int i = 0; s[i]; i++){
		if(s[i] == 'M'){
			if(dir == 0){
				if(!vis[x][y]) ans += mat[x][y];
				else ans += mat[x][y] / 2;
				vis[x][y] = 1;
				
				if(!vis[x-1][y]) ans += mat[x-1][y];
				else ans += mat[x-1][y] / 2;
				vis[x-1][y] = 1;

				y++;
			}
			else if(dir == 1){
				if(!vis[x-1][y-1]) ans += mat[x-1][y-1];
				else ans += mat[x-1][y-1] / 2;
				vis[x-1][y-1] = 1;
				
				if(!vis[x][y-1]) ans += mat[x][y-1];
				else ans += mat[x][y-1] / 2;
				vis[x][y-1] = 1;

				y--;
			}
			else if(dir == 2){
				if(!vis[x-1][y-1]) ans += mat[x-1][y-1];
				else ans += mat[x-1][y-1] / 2;
				vis[x-1][y-1] = 1;
				
				if(!vis[x-1][y]) ans += mat[x-1][y];
				else ans += mat[x-1][y] / 2;
				vis[x-1][y] = 1;

				x--;
			}
			else if(dir == 3){

				if(!vis[x][y]) ans += mat[x][y];
				else ans += mat[x][y] / 2;
				vis[x][y] = 1;
				
				if(!vis[x][y-1]) ans += mat[x][y-1];
				else ans += mat[x][y-1] / 2;
				vis[x][y-1] = 1;

				x++;
			}
		}
		else if(s[i] == 'R'){
			if(dir == 0) dir = 3;
			else if(dir == 1) dir = 2;
			else if(dir == 2) dir = 0;
			else if(dir == 3) dir = 1;
		}
		else if(s[i] == 'L'){
			if(dir == 0) dir = 2;
			else if(dir == 1) dir = 3;
			else if(dir == 2) dir = 1;
			else if(dir == 3) dir = 0;
		}
		// printf("%d %d %lld\n", x, y, ans);
	}

	printf("%lld\n", ans);








	return 0;
}