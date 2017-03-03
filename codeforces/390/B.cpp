#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

char mat[20][20];
bool f(){
	for(int i = 0; i < 4; i++){
		if(mat[i][0] == 'x' &&
		   mat[i][1] == 'x' &&
		   mat[i][2] == 'x')
			return 1;
		if(mat[i][1] == 'x' &&
		   mat[i][2] == 'x' &&
		   mat[i][3] == 'x')
			return 1;
	}
	
	for(int j = 0; j < 4; j++){
		if(mat[0][j] == 'x' &&
		   mat[1][j] == 'x' &&
		   mat[2][j] == 'x')
			return 1;
		if(mat[1][j] == 'x' &&
		   mat[2][j] == 'x' &&
		   mat[3][j] == 'x')
			return 1;
	}

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			if(mat[i][j] == 'x' &&
			   mat[i+1][j+1] == 'x' &&
			   mat[i+2][j+2] == 'x')
				return 1;
		}
	}
	
	for(int i = 0; i < 2; i++){
		for(int j = 3; j >= 2; j--){
			if(mat[i][j] == 'x' &&
			   mat[i+1][j-1] == 'x' &&
			   mat[i+2][j-2] == 'x')
				return 1;
		}
	}
	
	return 0;
}

int main(){

	for(int i = 0; i < 4; i++)
		scanf(" %s", mat[i]);

	bool win = false;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(mat[i][j] != '.') continue;
			mat[i][j] = 'x';
			win |= f();
			mat[i][j] = '.';
		}
	}

	printf("%s\n", win ? "YES" : "NO");

	return 0;
}