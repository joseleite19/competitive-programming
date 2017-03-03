#include <bits/stdc++.h>

using namespace std;

int main(){
	char s[1000];

	for(int i = 1; i <= 150; i++){
		// sprintf(s, "wget http://maratona.ime.usp.br/hist/2013/resultados13/data/contest/E/output/E_%d", i);
		
		// sprintf(s, "if[[ -z $(./sol < input/B_%d > out && diff out output/B_%d ) ]]; then echo \"Erro no caso %d\"; fi", i, i, i);
		// sprintf(s, "if[[ -z $(./sol < input/B_%d > out && diff out output/B_%d ) ]]; then echo \"Erro no caso %d\"; fi", i, i, i);
		sprintf(s, "echo \"Teste %d:\" && ./sol < input/E_%d > out && diff out output/E_%d | grep . -c", i, i, i);
		// printf("%s\n", s);
		system(s);
	}

	return 0;
}