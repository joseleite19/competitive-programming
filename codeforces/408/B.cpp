#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int hole[1000006];

int main(){

	scanf("%d %d %d", &n, &m, &k);

	int x;

	for(int i = 0; i < m; i++){
		scanf("%d", &x);
		hole[x] = 1;
	}

	int u, v;

	int bone = 1;
	for(int i = 0; i < k; i++){
		if(hole[bone]) break;
		scanf("%d %d", &u, &v);
		if(bone == u) bone = v;
		else if(bone == v) bone = u;
	}

	printf("%d\n", bone);




	return 0;
}