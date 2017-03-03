#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, m;

int L, R, U, D;

char s[100];

int mat[500][500];

int main(){

	scanf("%d %d", &n, &m);

	int x, y;

	x = y = 0;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			x = i+U;
			y = j+R;
			printf("%d %d\n", min(x, n), min(y, m));
			fflush(stdout);

			scanf(" %s", s);
			if(s[0] == 'D' && s[1] == 'E') break;

			if(s[0] == 'L'){
				L++;
				R--;
			}
			if(s[0] == 'D'){
				D++;
				U--;

			}
			if(s[0] == 'R'){
				R++;
				// L = max(0, L-1);
			}
			if(s[0] == 'U'){
				U++;
				// D = max(0, D-1);
			}
		}
	}


	return 0;
}