#include <bits/stdc++.h>

using namespace std;

int main(){
	int p, j1, j2, r, a;

	scanf("%d %d %d %d %d", &p, &j1, &j2, &r, &a);

	if(r && a) printf("Jogador 2 ganha!\n");
	else if(r) printf("Jogador 1 ganha!\n");
	else if(a) printf("Jogador 1 ganha!\n");
	else if((j1 + j2) % 2 == 0){
		if(!p) printf("Jogador 2 ganha!\n");
		else printf("Jogador 1 ganha!\n");
	}
	else if(!p) printf("Jogador 1 ganha!\n");
	else printf("Jogador 2 ganha!\n");

	return 0;
}