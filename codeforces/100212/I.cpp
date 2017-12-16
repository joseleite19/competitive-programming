#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int N;
int M;

bool valido(int i, int j, int N, int M){

	if(i < 0 || i >= N || j < 0 || j >= M) return false;

	return true;
}

long long solve(int i, int j, bool matriz[][100]){

	if((N*M)%3 != 0) return 0;

	if(i == N) return 1;

	if(matriz[i][j]){
		j++;
		if(j == M){
			i++;
			j = 0;
		}
		return solve(i,j,matriz);
	}

	bool deu = true;

	bool deu2 = true;

	for(int k = 0; k < 3; k++){
		int ii = i;
		int jj = j + k;

		if(!(valido(ii,jj,N,M) and !matriz[ii][jj])) deu = false;
	}

	for(int k = 0; k < 3; k++){
		int ii = i+k;
		int jj = j;

		if(!(valido(ii,jj,N,M) and !matriz[ii][jj])) deu2 = false;
	}	

	long long opc1 = 0;
	long long opc2 = 0;

	if(deu){

		bool aux[100][100];

		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				aux[i][j] = matriz[i][j];
			}
		}

		for(int k = 0; k < 3; k++){
			int ii = i;
			int jj = j + k;
			aux[ii][jj] = true;
		}

		int jj = j + 2;
		int ii = i;
		if(jj == M-1){
			jj = 0;
			ii++;
		}

		opc1 = solve(ii,jj,aux);
		

	}

	if(deu2){

		bool aux1[100][100];

		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				aux1[i][j] = matriz[i][j];
			}
		}

		for(int k = 0; k < 3; k++){
			int ii = i + k;
			int jj = j;
			aux1[ii][jj] = true;
		}

		int jj = j+1;
		int ii = i;

		if(jj == M){
			jj = 0;
			ii++;
		}

		opc2 = solve(ii,jj,aux1);
	}

	return opc1 + opc2;
}

int main(){

			bool matriz[100][100];
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 30; j++){
			
			N = i;
			M = j;


			for(int i = 0; i < N; i++){
				for(int j = 0; j < M; j++){
					matriz[i][j] = false;
				}
			}

			printf("v[%d][%d] = %lld;\n",N,M,solve(0,0,matriz)); fflush(stdout);
		}
	}

	return 0;
}