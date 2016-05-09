#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>

int main(){
	int L, C, X[305][305];
	ii position[90005];

	while(scanf("%d %d", &L, &C) == 2){

		for(int i = 0; i < L; i++)
			for(int j = 0; j < C; j++){
				scanf("%d", &X[i][j]);
				position[ X[i][j] ] = ii(i, j);
			}

		int moves = 0;
		bool possible = true;
		for(int conteiner = 1; conteiner <= L*C; conteiner++){
			int x = position[conteiner].first;
			int y = position[conteiner].second;
			int a = conteiner / C;
			int b = conteiner % C;
			b--;
			if(b == -1){
				b = C-1;
				a--;
			}
			if(x == a && y == b) continue;
			if(x != a){
				moves++;
				for(int i = 0; i < C; i++){
					if(X[a][i] < conteiner) possible = false;
					swap(X[a][i], X[x][i]);
					swap(position[ X[a][i] ], position[ X[x][i] ]);
				}
			}
			if(y != b){
				moves++;
				for(int i = 0; i < L; i++){
					if(X[i][y] < conteiner) possible = false;
					swap(X[i][y], X[i][b]);
					swap(position[ X[i][y] ], position[ X[i][b] ]);
				}
			}
			if(!possible) break;
		}
		if(!possible) printf("*\n");
		else printf("%d\n", moves);
	}

	return 0;
}