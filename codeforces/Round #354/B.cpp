#include <bits/stdc++.h>

int n, v[3000], t;

int left(int p, int level){
	return p+level;
}

int right(int p, int level){
	return p+level+1;
}

void flow(int p, int level, int f){
	if(p > n*(n+1)/2) return;

	if(v[p] == (1 << n)){
		flow(p+level, level+1, f/2);
		flow(p+level+1, level+1, f/2);
	}
	else v[p] += f;
	// printf("%d %d\n", p, level);
}

int main(){

	memset(v, 0, sizeof v);

	scanf("%d %d", &n, &t);

	for(int i = 0; i < t; i++)
		flow(0, 1, (1<<n));

	int count = 0;
	for(int i = 0; i < n*(n+1)/2; i++){
		if(v[i] == (1 << n))
			count++;
	}

	printf("%d\n", count);

	return 0;
}