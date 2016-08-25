#include <bits/stdc++.h>

using namespace std;

int main(){
	char command[60];
	for(int i = 1; i < 5; i++){
		sprintf(command, "./testing < input/I_%d > out", i);
		system(command);
		sprintf(command, "diff output/I_%d out",  i);
		system(command);
	}

	return 0;
}