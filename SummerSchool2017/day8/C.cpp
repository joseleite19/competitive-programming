#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int n, m;
char mat[30][30];
int row[30],col[30];


int main(){
	file();
	int qtd = 0;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c", &mat[i][j]);
			if(mat[i][j] == '*'){
				col[j]++;
				row[i]++;
				qtd++;
			}
		}
	}
	int ans = 0;
	while(qtd){
		ans++;
		int maxl = 0,idl,maxc = 0,idc;
		for(int i = 0; i < n; i++){
			if(row[i] > maxl){
				maxl = row[i];
				idl = i;
			}
		}
		for(int j = 0; j < m; j++){
			if(col[j] > maxc){
				maxc = col[j];
				idc = j;
			}
		}
		//printf("%d %d\n",row[idl],col[idc] );
		if(mat[idl][idc] == '*') qtd -= row[idl] + col[idc] - 1;
		else qtd -= row[idl] + col[idc];
		for(int i = 0; i < n; i++){
			if(mat[i][idc] == '*'){
				mat[i][idc] = '.';
				col[idc]--;
				row[i]--;
			}
		}
		for(int i = 0; i < m; i++){
			if(mat[idl][i] == '*'){
				mat[idl][i] = '.';
				col[i]--;
				row[idl]--;
			}
		}
	}

	printf("%d\n",ans);
	// priority_queue<pair<int, int> > pq1, pq2; // qnt, <i, j>

	// for(int i = 0; i < n; i++){
	// 	int cnt = 0;
	// 	for(int j = 0; j < m; j++){
	// 		cnt += mat[i][j];
	// 	}
	// 	pq1.push(mp(cnt, i));
	// }
	

	// for(int j = 0; j < m; j++){
	// 	int cnt = 0;
	// 	for(int i = 0; i < n; i++){
	// 		cnt += mat[i][j];
	// 	}
	// 	pq2.push(mp(cnt, j));
	// }

	// while(!pq1.empty() || !pq2.empty()){

	// }
	





	return 0;
}