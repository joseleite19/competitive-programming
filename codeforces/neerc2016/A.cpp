#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("arquivo.in", "r", stdin);
	freopen("arquivo.out", "w", stdout);
}

int main(){
	// file();

	int w,h;

	scanf("%d %d", &w, &h);

	int x1,x2,y1,y2;

	scanf("%d %d", &x1, &y1);

	scanf("%d %d", &x2, &y2);

	int x1resp, x2resp, y1resp, y2resp;

	y1resp = 0;

	y2resp = h;

	x1resp = x1;

	x2resp = x2;

	if(x1 == x2){
		y1resp = y1;
		y2resp = y2;
		x1resp = 0;
		x2resp = w;
	}

	printf("%d %d %d %d\n", x1resp, y1resp, x2resp, y2resp);

	return 0;
}