/* Irina Tornado */
#include <bits/stdc++.h>

using namespace std;
// Borders:
//  0
// 3 1
//  2
bool border[505][505][4];

int bfs(){
	bool pushed[505][505];

	memset(pushed, 0, sizeof pushed);

	int tam = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));

	pushed[0][0] = true;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		tam++;
		if(x > 0 && !pushed[x-1][y] && !border[x][y][2]){
			q.push(make_pair(x-1, y));
			pushed[x-1][y] = true;
		}
		if(y > 0 && !pushed[x][y-1] && !border[x][y][3]){
			q.push(make_pair(x, y-1));
			pushed[x][y-1] = true;
		}
		if(x < 503 && !pushed[x+1][y] && !border[x][y][0]){
			q.push(make_pair(x+1, y));
			pushed[x+1][y] = true;
		}
		if(y < 503 && !pushed[x][y+1] && !border[x][y][1]){
			q.push(make_pair(x, y+1));
			pushed[x][y+1] = true;
		}
	}
	return tam;
}

int main(){
	int n, x1, x2, y1, y2;

	scanf("%d", &n);

	memset(border, 0, sizeof border);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if(y2 != y1){
			for(int j = min(y1, y2); j < max(y1, y2); j++)
				border[x1][j][2] = border[x1-1][j][0] = true;
		}
		else{
			for(int j = min(x1, x2); j < max(x1, x2); j++)
				border[j][y1][3] = border[j][y1-1][1] = true;
		}
	}

	int before = bfs();

	int k;
	scanf("%d", &k);

	for(int i = 0; i < k; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if(y1 < y2){
			border[x1][y1][2] = border[x1-1][y1][0] = false;
		}
		else if(y2 < y1){
			border[x1][y2][2] = border[x1-1][y2][0] = false;
		}
		else if(x1 < x2){
			border[x1][y1][3] = border[x1][y1-1][1] = false;
		}
		else{
			border[x2][y1][3] = border[x2][y1-1][1] = false;
		}
	}

	int after = bfs();

	printf("%d\n", after - before);

	return 0;
}