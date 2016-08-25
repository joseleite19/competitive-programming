#include <bits/stdc++.h>

using namespace std;

int main(){
	char command[60];
	for(int i = 1; i <= 28; i++){
		sprintf(command, "./testing < input/C_%d > out && diff output/C_%d out", i, i);
		system(command);
	}

	return 0;
}