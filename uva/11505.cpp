#include <bits/stdc++.h>

using namespace std;

// fd foward
// bk backward
// lt left
// rt right

int main(){
	int t;
	double cnv = acos(-1)/180;

	scanf("%d", &t);

	int n, z;
	char s[10];
	while(t--){
		scanf("%d", &n);
		double x, y, ang;
		x = y = ang = 0;

		for(int i = 0; i < n; i++){
			scanf(" %s %d", s, &z);
			if(s[0] == 'f'){
				x += cos(ang*cnv)*z;
				y += sin(ang*cnv)*z;
			}
			else if(s[0] == 'b'){
				x -= cos(ang*cnv)*z;
				y -= sin(ang*cnv)*z;
			}
			else if(s[0] == 'l'){
				ang += z;
			}
			else if(s[0] == 'r'){
				ang -= z;
			}
		}
		printf("%d\n", (int)(sqrt(x*x + y*y) + 0.5));
	}

	return 0;
}