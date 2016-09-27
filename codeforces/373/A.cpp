#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int n, v[1000005];

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	if(n == 1){
		if(v[0] == 15) printf("DOWN\n");
		else if(v[0] == 0) printf("UP\n");
		else printf("-1\n");
		return 0;
	}

	if(v[n-1] == 15){
		printf("DOWN\n");
		return 0;
	}
	if(v[n-1] == 0){
		printf("UP\n");
		return 0;
	}
	if(v[n-2] < v[n-1]){
		printf("UP\n");
		return 0;
	}
	else{
		printf("DOWN\n");
		return 0;
	}

	return 0;
}