#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)

using namespace std;

typedef long long ll;
const int N = 10000;

int dx[] = {1,1,1,  0,0,  -1,-1,-1};
int dy[] = {1,0,-1, 1,-1, -1,0,1};

int main(){

	int xi,yi,xf,yf;

	scanf("%d %d", &xi, &yi);
	scanf("%d %d", &xf, &yf);

	int resp = 2e9;

	for(int i = 0; i < 8; i++){

		int x = xf + dx[i];
		int y = yf + dy[i];

		int dist = abs(xi-x) + abs(yi-y);

		resp = min(2*dist + 8, resp);
	}

	printf("%d\n",resp);

	return 0;
}

