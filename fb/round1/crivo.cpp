#include <bits/stdc++.h>

#define MAXN 10000000

using namespace std;

int mark[MAXN+1];

vector<int> primes;

void crivo(){
	mark[0] = mark[1] = 1;

	int i;
	for(i = 2; i*i <= MAXN; i++){
		if(!mark[i]){
			primes.push_back(i);
			for(int j = i+i; j <= MAXN; j += i)
				mark[j] = 1;
		}
	}
	for(; i <= MAXN; i++)
		if(!mark[i])
			primes.push_back(i);
}

int main(){
	crivo();

	return 0;
}