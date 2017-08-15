#include <bits/stdc++.h>

using namespace std;

int v[100005];
int n;

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	int ans = 1;

	int inc = 1, dec = 1;

	for(int i = 1; i < n; i++){
		if(v[i] > v[i-1]) dec = 0;
		if(v[i] < v[i-1]) inc = 0;
		if(!dec && !inc){
			ans++;
			inc = dec = 1;
		}
	}

	printf("%d\n", ans);

	return 0;
}