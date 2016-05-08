#include <cstdio>
#include <queue>
#include <map>

using namespace std;

#define INF 2000000000
#define ii pair<int,int>

int isUpper(char c){
	if(c >= 'A' && c <= 'Z')
		return 1;
	return 0;
}

int can(char c, int bitmask){
	int id = (isUpper(c) ? c - 'A' : c - 'a');
	return ((1 & (bitmask >> id)) == isUpper(c));
}

int main(){
	char matriz[100][101];
	int distance[100][100], n, minimum;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf(" %s", matriz[i]);

	minimum = INF;
	for(int bitmask = 0; bitmask < (1 << 10); bitmask++){
		if(!can(matriz[0][0], bitmask)) continue;

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				distance[i][j] = INF;
		
		queue<ii >q;
		q.push(ii(0, 0));
		distance[0][0] = 1;
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if(x > 0 && can(matriz[x-1][y], bitmask) && distance[x-1][y] == INF){
				distance[x-1][y] = distance[x][y] + 1;
				q.push(ii(x-1, y));
			}
			if(x < n-1 && can(matriz[x+1][y], bitmask) && distance[x+1][y] == INF){
				distance[x+1][y] = distance[x][y] + 1;
				q.push(ii(x+1, y));
			}
			if(y > 0 && can(matriz[x][y-1], bitmask) && distance[x][y-1] == INF){
				distance[x][y-1] = distance[x][y] + 1;
				q.push(ii(x, y-1));
			}
			if(y < n-1 && can(matriz[x][y+1], bitmask) && distance[x][y+1] == INF){
				distance[x][y+1] = distance[x][y] + 1;
				q.push(ii(x, y+1));
			}
		}
		minimum = min(minimum, distance[n-1][n-1]);
	}
	printf("%d\n", minimum == INF ? -1 : minimum);

	return 0;
}
