#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int n, k, t;

	scanf("%d %d", &n, &k);

	k = 240 - k;

	int qnt = 0;

	for(int i = 1; i <= n; i++){
		if(5*i <= k){
			k -= 5*i;
			qnt++;
		}
	}

	printf("%d\n", qnt);


	return 0;
}