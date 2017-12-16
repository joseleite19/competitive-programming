#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 2050;

ll resp[N][N];
int v[N];

int main(){

	int n;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	bool deu = true;

	for(int i = n-1; i >= 1; i--){
		
		int aux;

		if(v[i-1] == 0 and v[i] == 0){
			aux = 0;
			resp[i][0] = -1;
		}
		else if(v[i-1] == 0 and v[i] == 1){
			aux = 1;
			resp[i][n-1-i] = -1;
		}
		else if(v[i-1] == 1 and v[i] == 0){
			aux = 1;
			resp[i][n-1-i] = 1;
		}
		else{
			aux = 0;
			resp[i][0] = 1;
		}

		if(i == n-1) continue;

		if(aux){
			for(int j = n-2-i; j >= 0; j--){
				resp[i][j] = resp[i][j+1] - resp[i+1][j];
				if(abs(resp[i][j]) > 1000000000){
					deu = false;
					printf("..%d\n", i);
					i = 0;
					break;
				} 
			}
		}
		else{
			for(int j = 1; j <= n-1-i; j++){
				resp[i][j] = resp[i+1][j-1] + resp[i][j-1];
				if(abs(resp[i][j]) > 1000000000){
					deu = false;
					i = 0;
					break;
				} 
			}
		}
	}

	if(v[0] == 0){
		resp[0][0] = -1000000000;
		for(int j = 1; j <= n-1; j++){
			resp[0][j] = resp[0+1][j-1] + resp[0][j-1];
			if(abs(resp[0][j]) > 1000000000){
				deu = false;
			} 
		}

	}
	else{
		resp[0][0] = 1000000000;
		for(int j = n-2; j >= 0; j--){
			resp[0][j] = resp[0][j+1] - resp[0+1][j];
			if(abs(resp[0][j]) > 1000000000){
				printf("..%d\n", j);
				deu = false;
			} 
		}
	}

	if(!deu){
		printf("IMPOSSIBLE\n");
		return 0;
	}

	for(int i = 0 ; i < 1; i++){
		for(int j = 0; j < n; j++){
			printf("%lld ",resp[i][j] );
		}
		printf("\n");
	}

    return 0;
}
