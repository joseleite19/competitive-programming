#include <bits/stdc++.h>

int p[10004];

int f(int x){
	return (x == p[x] ? x : p[x] = f(p[x]));
}

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		p[i] = i;

	int cnt = n;

	int x;
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		if(f(x) != f(i)){
			p[f(x)] = f(i);
			cnt--;
		}
	}

	printf("%d\n", cnt);
	
	return 0;
}