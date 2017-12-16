#include <bits/stdc++.h>

using namespace std;

int vertices,arestas;

int main(){

	int casos;

	scanf("%d", &casos);

	while(casos--){

		scanf("%d %d", &vertices, &arestas);

		while(arestas--){
			int v1,v2;

			scanf("%d %d", &v1, &v2);

			v1--;
			v2--;
		}
		printf("%d\n", vertices-1);
	}

	return 0;
}