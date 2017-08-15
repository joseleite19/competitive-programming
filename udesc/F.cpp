#include <bits/stdc++.h>

using namespace std;

int main(){

	int casos;

	scanf("%d",&casos);

	while(casos--){

		int resp[10];

		int A,B,C;

		for(int i = 0; i < 9; i++){
			scanf("%d", &resp[i]);
			if(i == 0) A = resp[i];
			if(i == 4) B = resp[i];
			if(i == 8) C = resp[i];
		}

		bool gabarita = true;

		for(int i = 0; i < 9; i++){
			int val = resp[i];
			if(i == 0) continue;
			if(i == 4) continue;
			if(i == 8) continue;

			if(i == 1){
				if(((A+C)*2)%10 != val) gabarita = false; 
			}

			if(i == 2){
				if((B*3)%10 != val) gabarita = false;
			}

			if(i == 3){
				if((A+B)%10 != val) gabarita = false;
			}

			if(i == 5){
				if((C*4)%10 != val) gabarita = false;
			}

			if(i == 6){
				if((A*8)%10 != val) gabarita = false;
			}

			if(i == 7){
				if((A+B+C)%10 != val) gabarita = false;
			}
		}

		if(gabarita) printf("SIM\n");
		else printf("NAO\n");

	}

	return 0;
}