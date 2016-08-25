#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, n, m;
	char matriz[1005][1005];

	scanf("%d", &t);

	while(t--){
		scanf("%d %d", &n, &m);	

		vector<vector<pair<int,int> > > vertical(n + 2, vector<pair<int,int> >(m + 2, make_pair(0,0)));
		vector<vector<pair<int,int> > > horizontal(n + 2, vector<pair<int,int> >(m + 2, make_pair(0,0)));
		
		for(int i = 0; i < n; i++)
			scanf(" %s", matriz[i]);
		
		for(int i = n-1; i >= 0; i--){
			for(int j = m-1; j >= 0; j--){
				if(matriz[i][j] == '.'){
					vertical[i][j].first += 1 + vertical[i+1][j].first;
					// cnt[i][j].second += 1 + cnt[i][j+1].second;
				}
			}
		}
		for(int i = 0; i < vertical.size(); i++){
			for(int j = 0; j < vertical[i].size(); j++){
				// if(!vertical[i][j].first)
					// vertical[i][j].first = 1e9;
				horizontal[i][j].second = 1e9;
			}
		}
		
		for(int i = n-1; i >= 0; i--){
			for(int j = m-1; j >= 0; j--){
				if(matriz[i][j] == '.'){
					horizontal[i][j].first += 1 + horizontal[i][j+1].first;
					horizontal[i][j].second = min(vertical[i][j].first, horizontal[i][j+1].second);
				}
			}
		}


		// for(int i = 0; i < n; i++){
		// 	for(int j = 0; j < m; j++)
		// 		printf("(%d, %d, %2d) ", horizontal[i][j].first, horizontal[i][j].second, vertical[i][j].first == 1e9 ? -1 : vertical[i][j].first);
		// 	printf("\n");
		// }

		int side = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				side = max(side, min(horizontal[i][j].first, horizontal[i][j].second));
		printf("The side of the square is %d and the locations are:\n", side);
		int count = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(side == min(horizontal[i][j].first, horizontal[i][j].second)){
					count++;
					printf("%d %d\n", i+1, j+1);
				}
		printf("%d in total.\n", count);
	}


	return 0;
}