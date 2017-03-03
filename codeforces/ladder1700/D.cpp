#include <bits/stdc++.h>

using namespace std;

int main(){
	long long ans = 199998999997956;

	long long x = 999999999;
	long long y = 1000000000;
	int tot = 200000-1;
	for(int i = 0; i <= tot; i++){
		long long tmp = i*x + (tot-i)*y;
		if(tmp == ans) printf("%d\n", i);
	}


	return 0;
}