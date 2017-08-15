#include <bits/stdc++.h>

using namespace std;

void f(int peguei, long long valor){

	conj.insert(valor);

	for(int i = 0; i < n; i++){
		if(!(peguei & (1 << i))){
			f(peguei | (1 << i), valor+v[i]);
		}
	}
}

int main(){

	return 0;
}