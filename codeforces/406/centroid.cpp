#include <bits/stdc++.h>

using namespace std;

short int n;

vector <short int> grafo1[7050];
vector <short int> grafo2[7050];

vector <bool> vis1(7050,false);
vector <bool> vis2(7050,false);

short int resp[2][7050];

// 0 loop
// 1 ganha
// 2 perde

void dp(short int player, short int pos){

	if(player == 0){

		short int tipo = 2;

		for(short int i = 0; i < grafo1[pos].size(); i++){

			short int v = grafo1[pos][i];

			if(resp[1][v] == 1) continue;
			
			if(resp[1][v] == 2){
				tipo = 1;
				break;
			}

			if(vis2[v]){
				tipo = 0;
				continue;
			}

			vis1[pos] = true;

			dp(1,v);

			if(resp[1][v] == 2){
				tipo = 1;
				break;
			}

			if(resp[1][v] == 0){
				tipo = 0;
			}

		}

		resp[0][pos] = tipo;



	}
	else{

		short int tipo = 2;

		for(short int i = 0; i < grafo2[pos].size(); i++){

			short int v = grafo2[pos][i];

			if(resp[0][v] == 1) continue;
			
			if(resp[0][v] == 2){
				tipo = 1;
				break;
			}

			if(vis1[v]){
				tipo = 0;
				continue;
			}

			vis2[pos] = true;

			dp(0,v);

			if(resp[0][v] == 2){
				tipo = 1;
				break;
			}

			if(resp[0][v] == 0){
				tipo = 0;
			}

		}

		resp[1][pos] = tipo;

	}

}

int main(){

	scanf("%hd", &n);

	short int k1,k2;

	scanf("%hd", &k1);

	vector <short int> v1,v2;

	for(short int i = 0; i < k1; i++){
		short int val;
		scanf("%hd", &val);
		resp[0][n-val] = 1;	
		v1.push_back(val);
	}

	scanf("%hd", &k2);

	for(short int i = 0; i < k2; i++){
		short int val;
		scanf("%hd", &val);
		resp[1][n-val] = 1;
		v2.push_back(val);
	}

	resp[0][0] = 2;
	resp[1][0] = 2;

	for(short int i = 1; i < n; i++){
		for(short int j = 0; j < v1.size(); j++){
			grafo1[i].push_back((i+v1[j])%n);
		}
	}

	for(short int i = 1; i < n; i++){
		for(short int j = 0; j < v2.size(); j++){
			grafo2[i].push_back((i+v2[j])%n);
		}
	}

	for(short int i = 1; i < n; i++){
		dp(0,i);
	}

	for(short int i = 1; i < n; i++){
		dp(1,i);
	}

	for(short int i = 0; i < 2; i++){
		for(short int j = 1; j < n; j++){
			if(resp[i][j] == 0) printf("Loop ");
			else if(resp[i][j] == 1) printf("Win ");
			else if(resp[i][j] == 2) printf("Lose ");
		}
		printf("\n");
	}

	return 0;	
}