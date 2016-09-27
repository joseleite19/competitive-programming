#include <bits/stdc++.h>

using namespace std;

// N 1
// E 2
// S 4
// W 8
// NE 3
// SE 6
// SW 12
// NW 9

int main(){
	char s[205];

	for(int tc = 1; scanf("%s", s) == 1 && s[0] != 'E'; tc++){
		double x = 0, y = 0;

		int tam = strlen(s);
		int n = 0, flag = 0;
		for(int i = 0; i < tam; i++){
			if(s[i] >= '0' && s[i] <= '9'){
				n = 10*n + (s[i]-'0');
				continue;
			}
			if(s[i] == 'N'){ flag += 1; continue; }
			if(s[i] == 'E'){ flag += 2; continue; }
			if(s[i] == 'S'){ flag += 4; continue; }
			if(s[i] == 'W'){ flag += 8; continue; }

			double tmp = n/sqrt(2);

			if(flag == 1) y += n;
			if(flag == 4) y -= n;
			if(flag == 2) x += n;
			if(flag == 8) x -= n;
			if(flag == 3) x += tmp, y += tmp;
			if(flag == 6) x += tmp, y -= tmp;
			if(flag == 12) x -= tmp, y -= tmp;
			if(flag == 9) x -= tmp, y += tmp;

			flag = 0;
			n = 0;
		}
		printf("Map #%d\nThe treasure is located at (%.3lf,%.3lf).\nThe distance to the treasure is %.3lf.\n\n", tc, x, y, sqrt(x*x+y*y));
	}

	return 0;
}