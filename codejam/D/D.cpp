#include <bits/stdc++.h>

using namespace std;

int visr[502];
int visc[502];
int visp[502];
int viss[502];

int n;

inline bool can_row(int r){ return visr[r] == 0; }
inline bool can_column(int c){ return visc[c] == 0; }
inline bool can_p(int x, int y){ return visp[x-y+150] == 0; }
inline bool can_s(int x, int y){ return viss[x+y] == 0; }

inline void set_row(int r, int val){ visr[r] = val; }
inline void set_column(int c, int val){ visc[c] = val; }
inline void set_p(int x, int y, int val){ visp[x-y+150] = val; }
inline void set_s(int x, int y, int val){ viss[x+y] = val; }

int mat[5][5];

int cnt;
int qwe;

int bc(int x, int y){
	if(x == n && y == n-1){
		if(cnt == 10){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(mat[i][j] == 3) printf("0");
					if(mat[i][j] == 2) printf("+");
					if(mat[i][j] == 1) printf("x");
					if(mat[i][j] == 0) printf(".");
				}
				printf("\n");
			}
			printf("\n");
			qwe++;
		}
		return 0;
	}
	else if(x == n){
		return bc(0, y+1);
	}
	else{
		// max deixar em branco, botar x, botar +, botar o
		int ans = 0;
		ans = max(ans, bc(x+1, y));

		if(can_row(x) && can_column(y)){ //bota x
			set_row(x, 1);
			set_column(y, 1);
			// set_s(x, y, 1);
			// set_p(x, y, 1);
			cnt++;
			mat[x][y] = 1;
			ans = max(ans, bc(x+1, y)+1);
			mat[x][y] = 0;
			cnt--;
			// set_s(x, y, 0);
			// set_p(x, y, 0);
			set_column(y, 0);
			set_row(x, 0);
		}
		if(can_p(x, y) && can_s(x, y)){ //bota +
			// set_row(x, 1);
			// set_column(y, 1);
			set_s(x, y, 1);
			set_p(x, y, 1);
			cnt++;
			mat[x][y] = 2;
			ans = max(ans, bc(x+1, y)+1);
			mat[x][y] = 0;
			cnt--;
			set_s(x, y, 0);
			set_p(x, y, 0);
			// set_column(y, 0);
			// set_row(x, 0);
		}
		if(can_row(x) && can_column(y) && can_p(x, y) && can_s(x, y)){
			set_row(x, 1);
			set_column(y, 1);
			set_s(x, y, 1);
			set_p(x, y, 1);
			cnt += 2;
			mat[x][y] = 3;
			ans = max(ans, bc(x+1, y)+2);
			mat[x][y] = 0;
			cnt -= 2;
			set_s(x, y, 0);
			set_p(x, y, 0);
			set_column(y, 0);
			set_row(x, 0);
		}
		// printf("%d %d %d\n", x, y, ans);
		return ans;
	}
}



int main(){

	n = 4;

	printf("%d\n", bc(0, 0));
	printf("%d\n", qwe);


	return 0;
}