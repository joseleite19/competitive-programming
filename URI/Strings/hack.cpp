#include <bits/stdc++.h>

using namespace std;

int main(){
	char s[1000];

	for(int i = 1; i <= 68; i++){
		// sprintf(s, "if[[ -z $(./sol < input/B_%d > out && diff out output/B_%d ) ]]; then echo \"Erro no caso %d\"; fi", i, i, i);
		// sprintf(s, "if[[ -z $(./sol < input/B_%d > out && diff out output/B_%d ) ]]; then echo \"Erro no caso %d\"; fi", i, i, i);
		sprintf(s, "echo \"Teste %d:\" && ./sol < input/B_%d > out && diff out output/B_%d | grep . -c", i, i, i);
		// printf("%s\n", s);
		system(s);
	}

	return 0;
}