#include <bits/stdc++.h>

using namespace std;

int main(){
	int x, y;

	while(scanf("%d %d", &x, &y) == 2){
		if(x > y){
			x = x ^ y;
			y = x ^ y;
			x = x ^ y;
		}
		if(x & 1 == 0) x++;
		if(y & 1 == 0) y--;

		1 + 3 + 5 + 7 + 9 = 25
		
	}

	return 0;
}