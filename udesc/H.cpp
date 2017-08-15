#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		bool can = true;
		if(a > 12 || b > 12 || c > 12) can = false;
		if(24 - a - b - c > 12) can = false;
		if(24 - a - b - c < 6) can = false;
		int cnt = 0;
		if(!a) cnt++;
		if(!b) cnt++;
		if(!c) cnt++;
		if(24 - a - b - c == 0) cnt++;
		if(cnt > 1) can = false;

		printf("%s\n", can ? "adequada" : "nao adequada");
	}

	return 0;
}